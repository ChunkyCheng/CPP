/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 19:37:48 by jchuah            #+#    #+#             */
/*   Updated: 2026/01/13 20:50:36 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon
{

	public:
		Weapon(void);
		Weapon(std::string type);
		~Weapon(void);
		const std::string&	getType(void) const;
		void				setType(std::string type);

	private:
		std::string	_type;
};

#endif
