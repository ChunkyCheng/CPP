/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 21:35:13 by jchuah            #+#    #+#             */
/*   Updated: 2025/11/03 22:04:33 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

static bool isBlank(const std::string &str)
{
	return str.find_first_not_of(" \t\n\r\f\v") == std::string::npos;
}

Contact::Contact()
{
	std::cin.clear();
	while (isBlank(_first_name))
	{
		std::cout << "Enter first name: ";
		std::getline(std::cin, _first_name);
	}
	while (isBlank(_last_name))
	{
		std::cout << "Enter last name: ";
		std::getline(std::cin, _last_name);
	}
	while (isBlank(_nickname))
	{
		std::cout << "Enter nickname: ";
		std::getline(std::cin, _nickname);
	}
	while (isBlank(_number))
	{
		std::cout << "Enter phone number: ";
		std::getline(std::cin, _number);
	}
	while (isBlank(_secret))
	{
		std::cout << "Enter darkest secret: ";
		std::getline(std::cin, _secret);
	}
}

Contact::~Contact() {}

std::string	Contact::getFirstName(void) const
{
	return(_first_name);
}

std::string	Contact::getLastName(void) const
{
	return(_last_name);
}

std::string	Contact::getNickname(void) const
{
	return(_nickname);
}

std::string	Contact::getNumber(void) const
{
	return(_number);
}

std::string	Contact::getSecret(void) const
{
	return(_secret);
}

void	Contact::setFirstName(const std::string &str)
{
	_first_name = str;
}

void	Contact::setLastName(const std::string &str)
{
	_last_name = str;
}

void	Contact::setNickname(const std::string &str)
{
	_nickname = str;
}

void	Contact::setNumber(const std::string &str)
{
	_number = str;
}

void	Contact::setSecret(const std::string &str)
{
	_secret = str;
}
