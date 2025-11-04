/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jchuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:07:06 by jchuah            #+#    #+#             */
/*   Updated: 2025/11/04 17:22:18 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>
#include "Phonebook.hpp"

static bool isBlank(const std::string &str)
{
	return str.find_first_not_of(" \t\n\r\f\v") == std::string::npos;
}

Phonebook::Phonebook()
{
	std::string	input;

	while (1)
	{
		input = "";
		std::cout << "Input ADD, SEARCH or EXIT" << std::endl;
		while (isBlank(input))
		{
			std::cout << "> ";
			std::getline(std::cin, input);
		}
		if (input == "ADD")
			;
		if (input == "SEARCH")
			;
		if (input == "EXIT")
			return ;
		else
			std::cout << "Invalid command" << std::endl;
	}
}

Phonebook::~Phonebook() {}
