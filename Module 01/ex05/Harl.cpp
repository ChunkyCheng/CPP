/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:24:27 by jchuah            #+#    #+#             */
/*   Updated: 2026/01/14 16:24:39 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

const Harl::s_entry	Harl::_complain_table[] =
{
	{"DEBUG", &Harl::debug},
	{"INFO", &Harl::info},
	{"WARNING", &Harl::warning},
	{"ERROR", &Harl::error}
};

const int	Harl::_table_size = sizeof(Harl::_complain_table) / sizeof(Harl::s_entry);

void	Harl::debug(void)
{
	std::cout <<	"[Harl] ";
	std::cout << 	"I love having extra bacon for my "
					"7XL-double-cheese-triple-pickle-special-ketchup burger. "
					"I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout <<	"[Harl] ";
	std::cout <<	"I cannot believe adding extra bacon costs more money. "
					"You didn’t put enough bacon in my burger! "
					"If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout <<	"[Harl] ";
	std::cout <<	"I think I deserve to have some extra bacon for free. "
					"I’ve been coming for years, "
					"whereas you started working here just last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout <<	"[Harl] ";
	std::cout <<	"This is unacceptable! "
					"I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	int	i;

	i = 0;
	while (i < _table_size)
	{
		if (level == _complain_table[i].level)
		{
			(this->*_complain_table[i].action)();
			return ;
		}
		i++;
	}
}
