/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:24:27 by jchuah            #+#    #+#             */
/*   Updated: 2026/01/14 20:01:01 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

std::string const	Harl::levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
const int			Harl::level_count = sizeof(Harl::levels) / sizeof(std::string);

void	Harl::debug(void)
{
	std::cout <<	"[ DEBUG ]\n";
	std::cout << 	"I love having extra bacon for my "
					"7XL-double-cheese-triple-pickle-special-ketchup burger. "
					"I really do!\n" << std::endl;
}

void	Harl::info(void)
{
	std::cout <<	"[ INFO ]\n";
	std::cout <<	"I cannot believe adding extra bacon costs more money. "
					"You didn’t put enough bacon in my burger! "
					"If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void	Harl::warning(void)
{
	std::cout <<	"[ WARNING ]\n";
	std::cout <<	"I think I deserve to have some extra bacon for free. "
					"I’ve been coming for years, "
					"whereas you started working here just last month.\n" << std::endl;
}

void	Harl::error(void)
{
	std::cout <<	"[ ERROR ]\n";
	std::cout <<	"This is unacceptable! "
					"I want to speak to the manager now.\n" << std::endl;
}

void	Harl::complain(std::string level)
{
	int	i;

	i = 0;
	while (i < level_count)
	{
		if (level == levels[i])
			break ;
		i++;
	}
	switch (i)
	{
		case 0:
			Harl::debug();
			//fallthrough
		case 1:
			Harl::info();
			//fallthrough
		case 2:
			Harl::warning();
			//fallthrough
		case 3:
			Harl::error();
			break ;
		default:
			std::cout	<< "[ Probably complaining about insignificant problems ]"
						<< std::endl;
			break ;
	}
}
