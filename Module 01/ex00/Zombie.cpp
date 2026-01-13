/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 18:12:24 by jchuah            #+#    #+#             */
/*   Updated: 2026/01/13 19:10:46 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	_name = name;
	std::cout << "Zombie " << _name << " created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << _name << " destroyed" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
