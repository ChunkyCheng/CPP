#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>
# include "AForm.hpp"

class	ShrubberyCreationForm : public AForm
{
	private:
		ShrubberyCreationForm(void);
	public:
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm(void);

		void	_action(void) const;

	protected:
	private:
		static const int	SIGN_GRADE;
		static const int	EXEC_GRADE;
};

#endif
