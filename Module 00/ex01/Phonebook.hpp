/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 20:31:19 by jchuah            #+#    #+#             */
/*   Updated: 2025/11/04 17:14:46 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class	Phonebook
{
	public:
		Phonebook();
		~Phonebook();
		
		void	add_contact(void);
		void	search(void);
		void	exit(void);

	private:
		Contact	_contacts[8];
		int		_contact_count;
};

#endif
