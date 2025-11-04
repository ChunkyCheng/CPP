/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 20:33:21 by jchuah            #+#    #+#             */
/*   Updated: 2025/11/03 21:55:46 by jchuah           ###   ########.fr       */
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

		void 		setFirstName(const std::string &str);
		void 		setLastName(const std::string &str);
		void 		setNickname(const std::string &str);
		void 		setNumber(const std::string &str);
		void 		setSecret(const std::string &str);

	private:
		std::string	_first_name;
		std::string _last_name;
		std::string	_nickname;
		std::string	_number;
		std::string	_secret;
};

#endif
