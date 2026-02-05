#include "ShrubberyCreationForm.hpp"
#include <fstream>

const int	ShrubberyCreationForm::SIGN_GRADE = 145;
const int	ShrubberyCreationForm::EXEC_GRADE = 137;

ShrubberyCreationForm::ShrubberyCreationForm(void)
	:AForm("ShrubberyCreationForm", "", SIGN_GRADE, EXEC_GRADE)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	:AForm("ShrubberyCreationForm", target, SIGN_GRADE, EXEC_GRADE)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	:AForm(other)
{
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

void	ShrubberyCreationForm::_action(void) const
{
	std::string		filename;
	std::ofstream	outfile;

	filename = getTarget() + "_shrubbery";
	outfile.open(filename.c_str(), std::ios::app);
	if (!outfile.is_open())
	{
		std::cerr << "Error opening " << std::endl;
		return ;
	}
	outfile << "\n";
	outfile <<
				"       _-_                _-_                _-_\n"
				"    /~~   ~~\\          /~~   ~~\\          /~~   ~~\\\n"
				" /~~         ~~\\    /~~         ~~\\    /~~         ~~\\\n"
				"{               }  {               }  {               }\n"
				" \\  _-     -_  /    \\  _-     -_  /    \\  _-     -_  /\n"
				"   ~  \\\\ //  ~        ~  \\\\ //  ~        ~  \\\\ //  ~\n"
				"_- -   | | _- _    _- -   | | _- _    _- -   | | _- _\n"
				"  _ -  | |   -_      _ -  | |   -_      _ -  | |   -_\n"
				"      // \\\\              // \\\\              // \\\\" << std::endl;
}

