/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 20:33:21 by jchuah            #+#    #+#             */
/*   Updated: 2025/11/06 15:22:52 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class	Contact
{
	public:
		Contact();
		~Contact();

		std::string getFirstName(void) const;
		std::string getLastName(void) const;
		std::string getNickname(void) const;
		std::string getNumber(void) const;
		std::string	getSecret(void) const;

		void		get_info(void);

	private:
		std::string	_first_name;
		std::string _last_name;
		std::string	_nickname;
		std::string	_number;
		std::string	_secret;
};

#endif
