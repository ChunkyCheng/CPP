/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 18:34:41 by jchuah            #+#    #+#             */
/*   Updated: 2026/01/13 19:21:32 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name);

int	main(void)
{
	Zombie		*horde;
	int			size;
	std::string	name;

	size = 10;
	name = "gaylord";
	horde = zombieHorde(size, name);
	while (size--)
		horde[size].announce();
	delete[] horde;
}
