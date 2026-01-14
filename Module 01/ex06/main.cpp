/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:19:42 by jchuah            #+#    #+#             */
/*   Updated: 2026/01/14 20:01:40 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	Harl	complainer;

	if (argc != 2)
	{
		std::cout << "Usage: " << argv[0] << " <level>" << std::endl;
		return (1);
	}
	complainer.complain(argv[1]);
}
