#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), _target(copy._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	if (this != &copy)
	{
		AForm::operator=(copy);
	}
	return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor)
{
	AForm::isValidToExecute(executor);
	std::cout << "Sending shrubbery into " << this->_target << "_shrubbery." << std::endl;
	std::ofstream Tree_file((_target + "_shrubbery").c_str());
	if (!Tree_file.is_open())
		throw ShrubberyCreationForm::FileCreationException();
	Tree_file << "   			 # #### ####\n"
			  << "         ### /#|### |/####\n"
			  << "       ###/#/ ||/##/_/##/_#\n"
			  << "     ###  |/###|/ |/ # ###\n"
			  << "   ##_|_#|_### | #/###_/_####\n"
			  << "  ## #### # | #| /  #### ##/##\n"
			  << "   _#_--###`  |{,###---###-~-\n"
			  << "			   		|||\n"
			  << "			   		|||\n"
			  << "			   		|||\n"
			  << "        , -=-~{ .-^- _\n";
	Tree_file.close();
}

const char *ShrubberyCreationForm::FileCreationException::what() const throw()
{
	return ("Failed to create file for shrubbery.");
}

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &ShrubberyCreationForm)
{
	out << "ShrubberyCreationForm name: " << ShrubberyCreationForm.getName() << ", is signed: " << ShrubberyCreationForm.getIsSigned() << ", grade required to sign: " << ShrubberyCreationForm.getGradeRequiredToSign() << ", grade required to execute: " << ShrubberyCreationForm.getGradeRequiredToExecute() << std::endl;
	return (out);
}