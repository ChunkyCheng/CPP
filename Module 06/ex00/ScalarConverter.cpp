#include "ScalarConverter.hpp"
#include <cerrno>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <climits>
#include <iostream>
#include <sstream>

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& other)
{
	if (this != &other)
	{
	}
	return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
}

static std::string	getInputType(const std::string& input)
{
	size_t	len;
	size_t	decimal_pos;
	size_t	i;

	if (input == "nanf" || input == "+inff" || input == "-inff")
		return ("FLOAT");
	if (input == "nan" || input == "+inf" || input == "-inf")
		return ("DOUBLE");
	len = input.length();
	if (len == 0)
		return ("BADINPUT");
	if (len == 3 && input[0] == '\'' && input[2] == '\'')
		return ("CHAR");
	decimal_pos = input.find(".");
	if (decimal_pos != 0 && decimal_pos != len - 1
		&& decimal_pos == input.rfind("."))
	{
		i = 0;
		if (input[i] == '-' || input[i] == '+')
			++i;
		while (i < len)
		{
			if (!std::isdigit(input[i]) && input[i] != '.')
			{
				if (input[i] == 'f' && i != 0 && i == len - 1)
					return ("FLOAT");
				else
					return ("BADINPUT");
			}
			++i;
		}
		if (decimal_pos != std::string::npos)
			return ("DOUBLE");
		return ("INTEGER");
	}
	return ("BADINPUT");
}

static void	remove_trailing_zeroes(std::string& str)
{
	size_t	pos;

	pos = str.find_last_not_of('0');
	if (pos != std::string::npos)
	{
		if (str[pos] == '.')
			str.erase(pos + 2);
		else
			str.erase(pos + 1);
	}
}

static void	handle_char(const std::string& input, std::string output[4])
{
	std::stringstream	c;
	std::stringstream	i;
	std::stringstream	f;
	std::stringstream	d;

	if (std::isprint(input[1]))
		c << "\'" << input[1] << "\'";
	else
		c << "Non displayable";
	i << static_cast<int>(input[1]);
	f << static_cast<float>(input[1]) << ".0f";
	d << static_cast<double>(input[1]) << ".0";
	output[0] = c.str();
	output[1] = i.str();
	output[2] = f.str();
	output[3] = d.str();
}

static void	handle_int(const std::string& input, std::string output[4])
{
	long long			num_ll;
	int					num_i;
	char				c;
	std::stringstream	streams[4];

	num_ll = std::strtoll(input.c_str(), NULL, 10);
	num_i = static_cast<int>(num_ll);
	c = static_cast<char>(num_i);
	if (std::isprint(c))
		streams[0] << "'" << c << "'";
	else
		streams[0] << "Non displayable";
	streams[1] << num_i;
	if (errno == ERANGE || num_ll > INT_MAX || num_ll < INT_MIN)
	{
		streams[1] << " (overflowed/underflowed)";
		errno = 0;
	}
	streams[2] << std::fixed
			   << static_cast<float>(num_i);
	streams[3] << std::fixed
			   << static_cast<double>(num_i);
	output[0] = streams[0].str();
	output[1] = streams[1].str();
	output[2] = streams[2].str();
	remove_trailing_zeroes(output[2]);
	output[2] += "f";
	output[3] = streams[3].str();
	remove_trailing_zeroes(output[3]);
}

static void	handle_float(const std::string& input, std::string output[4])
{
	float				num_f;
	char				c;
	std::stringstream	streams[4];

	num_f = std::strtof(input.c_str(), NULL);
	if (std::isnan(num_f) || std::isinf(num_f))
	{
		streams[0] << "impossible";
		streams[1] << "impossible";
	}
	else
	{
		c = static_cast<char>(num_f);
		if (std::isprint(c))
			streams[0] << "'" << c << "'";
		else
			streams[0] << "Non displayable";
		streams[1] << static_cast<int>(num_f);
	}
	streams[2] << std::fixed
			   << num_f;
	streams[3] << std::fixed
			   << static_cast<double>(num_f);
	output[0] = streams[0].str();
	output[1] = streams[1].str();
	output[2] = streams[2].str();
	remove_trailing_zeroes(output[2]);
	output[2] += "f";
	if (errno == ERANGE)
	{
		output[2] += " (overflowed/underflowed)";
		errno = 0;
	}
	output[3] = streams[3].str();
	remove_trailing_zeroes(output[3]);
}

static void	handle_double(const std::string& input, std::string output[4])
{
	double				num_d;
	char				c;
	std::stringstream	streams[4];

	num_d = std::strtod(input.c_str(), NULL);
	if (std::isnan(num_d) || std::isinf(num_d))
	{
		streams[0] << "impossible";
		streams[1] << "impossible";
	}
	else
	{
		c = static_cast<char>(num_d);
		if (std::isprint(c))
			streams[0] << "'" << c << "'";
		else
			streams[0] << "Non displayable";
		streams[1] << static_cast<int>(num_d);
	}
	streams[2] << std::fixed
			   << static_cast<double>(num_d);
	streams[3] << std::fixed
			   << num_d;
	output[0] = streams[0].str();
	output[1] = streams[1].str();
	output[2] = streams[2].str();
	remove_trailing_zeroes(output[2]);
	output[2] += "f";
	output[3] = streams[3].str();
	remove_trailing_zeroes(output[3]);
	if (errno == ERANGE)
	{
		output[3] += " (overflowed/underflowed)";
		errno = 0;
	}
}

static void	handle_input(const std::string& input, int case_number)
{
	std::string	output[4];

	switch (case_number)
	{
		case 0:
			handle_char(input, output);
			break ;
		case 1:
			handle_int(input, output);
			break ;
		case 2:
			handle_float(input, output);
			break ;
		case 3:
			handle_double(input, output);
			break ;
		default:
			std::cerr << "ScalarConverter BadInput" << std::endl;
			return ;
	}
	std::cout << "char: " << output[0] << "\n"
			  << "int: " << output[1] << "\n"
			  << "float: " << output[2] << "\n"
			  << "double: " << output[3] << std::endl;
}

void	ScalarConverter::convert(const std::string& input)
{
	std::string	types[4] = {"CHAR", "INTEGER", "FLOAT", "DOUBLE"};
	std::string	type;
	int			i;

	type = getInputType(input);
	i = 0;
	while (i < 4)
	{
		if (types[i] == type)
			break ;
		++i;
	}
	handle_input(input, i);
}
