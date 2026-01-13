/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 18:15:01 by jchuah            #+#    #+#             */
/*   Updated: 2026/01/13 19:23:06 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
