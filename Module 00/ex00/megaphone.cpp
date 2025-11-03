/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:41:07 by jchuah            #+#    #+#             */
/*   Updated: 2025/11/03 19:04:32 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

static std::string	str_toupper(std::string str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = std::toupper(static_cast<unsigned char>(str[i]));
		i++;
	}
	return (str);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "LOUD AND UNBEARABLE FEEDBACK NOISE" << std::endl;
		return (0);
	}
	argv++;
	while (*argv)
	{
		std::cout << str_toupper(*argv);
		if (*(argv + 1))
			std::cout << " ";
		argv++;
	}
	std::cout << std::endl;
}
