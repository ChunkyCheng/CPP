#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <stdexcept>

class	Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat&	operator=(const Bureaucrat& other);
		~Bureaucrat(void);

		const std::string&	getName(void) const;
		int					getGrade(void) const;

		void	incrementGrade(void);
		void	decrementGrade(void);

		class	GradeTooHighException : public std::exception {};
		class	GradeTooLowException : public std::exception {};

	protected:
	private:
		std::string	_name;
		int			_grade;

		void	_checkGrade(void);

		static const int	GRADE_MIN;
		static const int	GRADE_MAX;
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj);

#endif
