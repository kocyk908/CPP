#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	// GRADE TOO HIGH
    try
    {
        Bureaucrat Tomas("Tommy", 0);
        Form    form1("Form", 15, 130);
        Tomas.signForm(form1);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }  
	std::cout << "-------------------------" << std::endl;

	// GRADE TOO LOW
    try
	{
        Bureaucrat Tadeo("Tadeo", 160);
        Form    form2("Form", 13, 12);
        Tadeo.signForm(form2);      
    }
	catch (std::exception &e)
	{
        std::cerr << e.what() << std::endl;
    }
    std::cout << "-------------------------" << std::endl;

    // FORM POSSIBLE TO SIGN WITH THIS BUREAUCRAT GRADE
    Bureaucrat Batyr("Batyr", 3);
    Form    form3("Form", 30, 35);
    try
	{
        Batyr.signForm(form3);   
    }
	catch (std::exception &e)
	{
        std::cerr << e.what() << std::endl;
    }
    std::cout << Batyr;
    std::cout << form3;    
	std::cout << "-------------------------" << std::endl;

	// FORM POSSIBLE !NOT! TO SIGN WITH THIS BUREAUCRAT GRADE
    Bureaucrat bureaucrat("Bureaucrat", 130);
    Form form("Form", 100, 150);
    try
	{
        bureaucrat.signForm(form);     
    }
	catch (std::exception &e)
	{
        std::cerr << e.what() << std::endl;
    }
    std::cout << bureaucrat;
    std::cout << form;

	return (0);
}