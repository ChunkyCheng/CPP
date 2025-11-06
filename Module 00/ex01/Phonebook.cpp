/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jchuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:07:06 by jchuah            #+#    #+#             */
/*   Updated: 2025/11/06 16:05:39 by jchuah           ###   ########.fr       */
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

	_contact_count = 0;
	_added_contacts = 0;
	while (1)
	{
		input = "";
		std::cin.clear();
		std::cout << "Input ADD, SEARCH or EXIT" << std::endl;
		while (isBlank(input))
		{
			std::cout << "> ";
			std::getline(std::cin, input);
			if (std::cin.eof())
				return ;
		}
		std::cout << "\n";
		if (input == "ADD")
		{
			_contacts[_contact_count].get_info();
			_contact_count = (_contact_count + 1) % 8;
			if (_added_contacts < 8)
				_added_contacts++;
			std::cout << "Contact added\n" << std::endl;
		}
		else if (input == "SEARCH")
			search_contacts();
		else if (input == "EXIT")
			return ;
		else
			std::cout << "Invalid command\n" << std::endl;
	}
}

Phonebook::~Phonebook() {}

static void	print_phonebook_format(std::string str)
{
	int	size;

	size = str.size();
	if (size > 10)
	{
		std::cout << str.substr(0, 9) << ".|";
		return ;
	}
	std::cout << str << std::string(10 - size, ' ') << '|';
}

void	Phonebook::search_contacts(void)
{
	int	i;

	if (_added_contacts == 0)
	{
		std::cout << "No contacts added\n" << std::endl;
		return ;
	}
	std::cout << "|index     |first name|last name |nickname  |" << '\n';
	i = 0;
	while (i < _added_contacts)
	{
		std::cout << '|' << i << "         |";
		print_phonebook_format(_contacts[i].getFirstName());
		print_phonebook_format(_contacts[i].getLastName());
		print_phonebook_format(_contacts[i].getNickname());
		std::cout << std::endl;
		i++;
	}
	display_contact_info();
}

void	Phonebook::display_contact_info(void)
{
	std::string	input;
	int			i;

	std::cin.clear();
	std::cout << "Input index number: ";
	std::getline(std::cin, input);
	i = input[0] - '0';
	if (input.size() != 1 || i + 1 > _added_contacts)
	{
		std::cout << "Invalid index\n" << std::endl;
		return ;
	}
	std::cout << "First Name     : " << _contacts[i].getFirstName() << "\n";
	std::cout << "Last Name      : " << _contacts[i].getLastName() << "\n";
	std::cout << "Nickname       : " << _contacts[i].getNickname() << "\n";
	std::cout << "Phone Number   : " << _contacts[i].getNumber() << "\n";
	std::cout << "Darkest Secret : " << _contacts[i].getSecret() << "\n";
	std::cout << std::endl;
}
