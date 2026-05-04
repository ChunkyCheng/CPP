#include "RPN.hpp"
#include <iostream>
#include <climits>

RPN::RPN(void)
{
}

RPN::RPN(const RPN& other)
{
	(void)other;
}

RPN&	RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
	}
	return (*this);
}

RPN::~RPN(void)
{
}

static bool	operate(std::stack<int>& stack, char operation)
{
	long long	operand1;
	long long	operand2;
	long long	result;

	if (stack.size() < 2)
	{
		std::cerr << "Error: invalid expression" << std::endl;
		return (false);
	}
	operand2 = static_cast<long long>(stack.top());
	stack.pop();
	operand1 = static_cast<long long>(stack.top());
	stack.pop();
	switch (std::string("+-*/").find(operation))
	{
		case 0:
			result = operand1 + operand2;
			break ;
		case 1:
			result = operand1 - operand2;
			break ;
		case 2:
			result = operand1 * operand2;
			break ;
		case 3:
		{
			if (operand2 == 0)
			{
				std::cerr << "Error: divide by zero" << std::endl;
				return (false);
			}
			result = operand1 / operand2;
			break ;
		}
		default:
			std::cerr << "Error: invalid token '" << operation << "'" << std::endl;
			return (false);
	}
	if (result > INT_MAX || result < INT_MIN)
	{
		std::cerr << "Error: integer overflow" << std::endl;
		return (false);
	}
	stack.push(static_cast<int>(result));
	return (true);
}

bool	RPN::calculateRPN(const std::string& input, int& result)
{
	std::stack<int>	stack;
	int				i;

	if (!std::isdigit(input[0]))
	{
		std::cerr << "Error: expression must start with an operand" << std::endl;
		return (false);
	}
	i = 0;
	while (input[i])
	{
		if (i % 2 == 1)
		{
			if(input[i] != ' ')
			{
				std::cerr << "Error: expected space between tokens" << std::endl;
				return (false);
			}
		}
		else if (std::isdigit(input[i]))
			stack.push(input[i] - '0');
		else if (operate(stack, input[i]) == false)
			return (false);
		++i;
	}
	if (i % 2 != 1 || stack.size() != 1)
	{
		std::cerr << "Error: incomplete expression" << std::endl;
		return (false);
	}
	result = stack.top();
	return (true);
}
