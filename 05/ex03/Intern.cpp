#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &copy)
{
	*this = copy;
}
Intern::~Intern()
{
}

Intern &Intern::operator=(const Intern &copy)
{
	(void)copy;
	return (*this);
}

//

AForm* Intern::createShrubbery(const std::string& FormTarget)
{
    return (new ShrubberyCreationForm(FormTarget));
}

AForm* Intern::createRobotomy(const std::string& FormTarget)
{
    return (new RobotomyRequestForm(FormTarget));
}

AForm* Intern::createPresidential(const std::string& FormTarget)
{
    return (new PresidentialPardonForm(FormTarget));
}
// Functions

AForm *Intern::makeForm(const std::string FormName, const std::string FormTarget)
{
	int i = 0;
	std::string possible_forms[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

    AForm* (Intern::*formCreators[])(const std::string&) = { &Intern::createShrubbery, &Intern::createRobotomy, &Intern::createPresidential };

	while (i <= 2)
	{
		if (FormName == possible_forms[i])
		{
            std::cout << "Intern creates " << FormName << std::endl;
            return (this->*formCreators[i])(FormTarget);
		}
		i++;
	}
	std::cout << FormName << " is not a valid Form name" << std::endl;
	return (0);		
}