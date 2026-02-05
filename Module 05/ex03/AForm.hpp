#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
{
	protected:
		AForm(void);
		AForm(const std::string& name, const std::string& target,
			  int grade_to_sign, int grade_to_execute);
		AForm(const AForm& other);
		AForm&	operator=(const AForm& other);
	
	public:
		virtual ~AForm(void);

		const std::string&	getName(void) const;
		const std::string&	getTarget(void) const;
		bool				getSigned(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExecute(void) const;

		void	beSigned(const Bureaucrat& signer);
		void	execute(const Bureaucrat& executor) const;

	private:
		std::string	_name;
		std::string	_target;
		bool		_signed;
		const int	_grade_to_sign;
		const int	_grade_to_execute;

		virtual void	_action(void) const;
		void			_checkGrade(void);

		static const int	GRADE_HIGHEST;
		static const int	GRADE_LOWEST;

	public:
		class	GradeTooHighException : public std::exception
		{
			public:
				const char	*what(void) const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				const char	*what(void) const throw();
		};
		class	NotSignedException : public std::exception
		{
			public:
				const char	*what(void) const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, const AForm& obj);

#endif
