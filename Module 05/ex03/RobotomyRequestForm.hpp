#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>
# include "AForm.hpp"

class	RobotomyRequestForm : public AForm
{
	private:
		RobotomyRequestForm(void);
	public:
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm(void);

		void	_action(void) const;

	protected:
	private:
		static const int	SIGN_GRADE;
		static const int	EXEC_GRADE;
};

#endif
