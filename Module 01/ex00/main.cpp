/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 18:34:41 by jchuah            #+#    #+#             */
/*   Updated: 2025/11/19 18:44:13 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int	main(void)
{
	Zombie	*heapguy;

	heapguy = newZombie("heapguy");
	heapguy->announce();
	delete (heapguy);
	randomChump("stackman");
}
