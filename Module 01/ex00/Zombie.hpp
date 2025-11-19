/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 18:15:01 by jchuah            #+#    #+#             */
/*   Updated: 2025/11/19 18:41:32 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class	Zombie
{
	public:
		Zombie(std::string);
		~Zombie();

		void	announce(void);
	
	private:
		std::string	_name;
};
