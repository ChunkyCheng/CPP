#include "RPN.hpp"
#include <iostream>

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
	int	operand1;
	int	operand2;

	if (stack.size() < 2)
	{
		std::cerr << "Error: invalid expression" << std::endl;
		return (false);
	}
	operand2 = stack.top();
	stack.pop();
	operand1 = stack.top();
	stack.pop();
	switch (std::string("+-*/").find(operation))
	{
		case 0:
			stack.push(operand1 + operand2);
			break ;
		case 1:
			stack.push(operand1 - operand2);
			break ;
		case 2:
			stack.push(operand1 * operand2);
			break ;
		case 3:
			stack.push(operand1 / operand2);
			break ;
		default:
			std::cerr << "Error: invalid token '" << operation << "'" << std::endl;
			return (false);
	}
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
