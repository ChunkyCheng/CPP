#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>
# include "AForm.hpp"

class	PresidentialPardonForm : public AForm
{
	private:
		PresidentialPardonForm(void);
	public:
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm(void);

		void	_action(void) const;

	protected:
	private:
		static const int	SIGN_GRADE;
		static const int	EXEC_GRADE;
};

#endif
