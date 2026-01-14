/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:19:33 by jchuah            #+#    #+#             */
/*   Updated: 2026/01/14 16:28:06 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class	Harl
{
	public:
		Harl(void);
		~Harl(void);

		void	complain(std::string level);

	private:
		void	debug(void);
		void	warning(void);
		void	info(void);
		void	error(void);

		struct s_entry
		{
			const std::string	level;
			void 				(Harl::*action)();
		};
		static const s_entry	_complain_table[];
		static const int		_table_size;
};

#endif
