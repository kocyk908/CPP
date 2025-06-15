#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), _target(copy._target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	if (this != &copy)
	{
		AForm::operator=(copy);
	}
	return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor)
{
	AForm::isValidToExecute(executor);
	std::cout << "Wrrrr wrrrr wrrrrr" << std::endl;
	std::srand(std::time(0));
	int num = rand();
	int canRobotomize = num % 2;

	if (canRobotomize)
	{
		std::cout << "RobotomyRequestForm " << _target << " has been robotomized successfully" << std::endl;
	}
	else
	{
        std::cout << "RobotomyRequestForm " << _target << " has failed to be robotomized" << std::endl;
	}
}