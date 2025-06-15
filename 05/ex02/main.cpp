#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    std::cout << "--------------- EXECUTE OPTION ---------------" << std::endl;
    
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
        robotomyRequestForm.beSigned(bureaucrat);
        presidentialPardonForm.beSigned(bureaucrat);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
	
    std::cout << " AFTER SIGNING" << "\n\n";
   
    std::cout << shrubberyCreationForm << std::endl;
    std::cout << robotomyRequestForm << std::endl;
    std::cout << presidentialPardonForm << std::endl;

    try
    {
        bureaucrat.executeForm(shrubberyCreationForm);
        bureaucrat.executeForm(robotomyRequestForm);
        bureaucrat.executeForm(presidentialPardonForm);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n\n--------------- CANNOT EXECUTE OPTION ---------------\n\n";

    Bureaucrat bureaucrat2("Bureaucrat", 150);
    ShrubberyCreationForm shrubberyCreationForm2("ShrubberyCreationForm");
    RobotomyRequestForm robotomyRequestForm2("RobotomyRequestForm");
    PresidentialPardonForm presidentialPardonForm2("PresidentialPardonForm");
	
    std::cout << "\n AFTER CREATION" << "\n\n";

    std::cout << bureaucrat2 << std::endl;
    std::cout << shrubberyCreationForm2 << std::endl;
    std::cout << robotomyRequestForm2 << std::endl;
    std::cout << presidentialPardonForm2 << std::endl;

    try
    {
        shrubberyCreationForm2.beSigned(bureaucrat2);
        robotomyRequestForm2.beSigned(bureaucrat2);
        presidentialPardonForm2.beSigned(bureaucrat2);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
	
    std::cout << "\n AFTER SIGNING" << "\n\n";
   
    std::cout << shrubberyCreationForm2 << std::endl;
    std::cout << robotomyRequestForm2 << std::endl;
    std::cout << presidentialPardonForm2 << std::endl;

    try
    {
        bureaucrat2.executeForm(shrubberyCreationForm2);
        bureaucrat2.executeForm(robotomyRequestForm2);
        bureaucrat2.executeForm(presidentialPardonForm2);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

}