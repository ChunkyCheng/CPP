#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include <string>

class	Intern
{
	public:
		Intern(void);
		Intern(const Intern& other);
		Intern&	operator=(const Intern& other);
		~Intern(void);

		AForm	*makeForm(const std::string& name, const std::string& target);

	protected:
	private:
		static const std::string	_form_names[];
		static const int			_FORM_TYPES;
};

#endif
