#include "Bureaucrat.hpp"

int main()
{
	    // GRADE TOO HIGH
    try
    {
        Bureaucrat Tomas("Tommy", 0);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }  
	std::cout << "-------------------------" << std::endl;

		// GRADE TOO LOW
    try
    {
        Bureaucrat Tomas("Tommy", 151);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }  
	std::cout << "-------------------------" << std::endl;

			// GRADE OK
	Bureaucrat Tomas("Tommy", 1);
	std::cout << Tomas << std::endl;
    try
    {
        Tomas.decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
	std::cout << "After decrement: " << Tomas << std::endl;
	try
    {
        Tomas.incrementGrade();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
	std::cout << "After increment: " << Tomas << std::endl;
	try
    {
        Tomas.incrementGrade();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
	std::cout << "After increment: " << Tomas << std::endl;
	return (0);
}