#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
    Bureaucrat bureaucrat("Bureaucrat", 3);
    ShrubberyCreationForm shrubberyCreationForm("ShrubberyCreationForm");
    RobotomyRequestForm robotomyRequestForm("RobotomyRequestForm");
    PresidentialPardonForm presidentialPardonForm("PresidentialPardonForm");
	
    std::cout << "\n AFTER CREATION" << "\n\n";

    std::cout << bureaucrat << std::endl;
    std::cout << shrubberyCreationForm << std::endl;
    std::cout << robotomyRequestForm << std::endl;
    std::cout << presidentialPardonForm << std::endl;

    try
    {
        shrubberyCreationForm.beSigned(bureaucrat);
        bureaucrat.executeForm(shrubberyCreationForm);
        robotomyRequestForm.beSigned(bureaucrat);
        bureaucrat.executeForm(robotomyRequestForm);
        presidentialPardonForm.beSigned(bureaucrat);
        bureaucrat.executeForm(presidentialPardonForm);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
	
    std::cout << "\n AFTER SIGNING" << "\n\n";
   
    std::cout << shrubberyCreationForm << std::endl;
    std::cout << robotomyRequestForm << std::endl;
    std::cout << presidentialPardonForm << std::endl;

    std::cout << " INTERN" << "\n\n";

    Intern  Ryan;
    AForm   *some_form;

    some_form = Ryan.makeForm("Error name", "CEO");
    some_form = Ryan.makeForm("ShrubberyCreationForm", "Someone");

    std::cout << "\n FORM IS MADE" << "\n\n";
    std::cout << some_form->getName() << "\n\n";
}