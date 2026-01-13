/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 18:15:01 by jchuah            #+#    #+#             */
/*   Updated: 2026/01/13 20:34:07 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class	Zombie
{
	public:
		Zombie(void);
		Zombie(std::string);
		~Zombie(void);

		void	announce(void);
		void	setName(std::string name);
	
	private:
		std::string	_name;
};

#endif
