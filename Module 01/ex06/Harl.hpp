/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:19:33 by jchuah            #+#    #+#             */
/*   Updated: 2026/01/14 19:57:05 by jchuah           ###   ########.fr       */
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

		static std::string const	levels[];
		static const int			level_count;
};

#endif
