#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <iostream>
#include <climits>
#include <cmath>

BitcoinExchange::BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(std::ifstream& infile)
{
	std::string	line;
	std::string	date;
	double		exchange_value;
	char		*endptr;

	std::getline(infile, line);
	if (line != "date,exchange_rate")
		throw (CsvFormatException());
	while (std::getline(infile, line))
	{
		if (line.length() < 12)
			throw (CsvFormatException());
		if (std::isspace(line[0]))
			throw (CsvFormatException());
		if (!_isValidDate(line))
			throw (CsvFormatException());
		date = line.substr(0, 10);
		if (line[10] != ',')
			throw (CsvFormatException());
		if (!std::isdigit(line[11]))
			throw (CsvFormatException());
		exchange_value = std::strtod(line.c_str() + 11, &endptr);
		if (*endptr != '\0')
			throw (CsvFormatException());
		_database[date] = exchange_value;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
	:_database(other._database)
{
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		_database = other._database;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
}

double	BitcoinExchange::getExchangeRate(const std::string& date) const
{
	std::map<std::string, double>::const_iterator	it;

	it = _database.upper_bound(date);
	if (it == _database.begin())
		return (NAN);
	--it;
	return (it->second);
}

void	BitcoinExchange::printConversions(std::ifstream& infile) const
{
	std::string	line;
	std::string	date;
	double		inputValue;
	double		exchangeRate;
	char		*endptr;

	getline(infile, line);
	if (line != "date | value")
	{
		std::cerr << "invalid input file format" << std::endl;
		return ;
	}
	while (getline(infile, line))
	{
		date = line.substr(0, 10);
		if (line.length() < 14 || !_isValidDate(date) || line.substr(10, 3) != " | ")
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue ;
		}
		inputValue = std::strtod(line.c_str() + 13, &endptr);
		if (!std::isdigit(line[13]) || *endptr != '\0')
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue ;
		}
		exchangeRate = getExchangeRate(date);
		if (std::isnan(exchangeRate))
		{
			std::cout << "Error: no data from or before " << date << std::endl;
			continue ;
		}
		if (inputValue * exchangeRate > INT_MAX)
		{
			std::cout << "Error: too large a number" << std::endl;
			continue ;
		}
		std::cout << date << " => " << inputValue
				  << " = " << inputValue * exchangeRate << std::endl;
	}
}

bool	BitcoinExchange::_isValidDate(const std::string& date) const
{
	int	year;
	int	month;
	int	day;
	int	days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (date[4] != '-' || date[7] != '-')
		return (false);
	for (int i = 0; i < 4; ++i)
	{
		if (!std::isdigit(date[i]))
			return (false);
	}
	if (!std::isdigit(date[5]) || !std::isdigit(date[6])
		|| !std::isdigit(date[8]) || !std::isdigit(date[9]))
		return (false);
	year = std::strtol(date.c_str(), NULL, 10);
	month = std::strtol(date.c_str() + 5, NULL, 10);
	day = std::strtol(date.c_str() + 8, NULL, 10);
	if (year < 1)
		return (false);
	if (month < 1 || month > 12)
		return (false);
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		days_in_month[1]++;
	if (day < 1 || day > days_in_month[month - 1])
		return (false);
	return (true);
}



//===============================
//==========EXCEPTIONS===========
//===============================
const char	*BitcoinExchange::CsvFormatException::what(void) const throw()
{
	return ("BitcoinExchange::CsvFormatException");
}
