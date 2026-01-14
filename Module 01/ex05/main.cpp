/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:19:42 by jchuah            #+#    #+#             */
/*   Updated: 2026/01/14 16:21:08 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl	complainer;

	complainer.complain("ERROR");
	complainer.complain("WARNING");
	complainer.complain("INFO");
	complainer.complain("DEBUG");
	complainer.complain("nothing");
}
