#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"

class Aform;

class Intern
{
	private:
	    AForm* createShrubbery(const std::string &target);
    	AForm* createRobotomy(const std::string &target);
    	AForm* createPresidential(const std::string &target);

	public:
		Intern();
		Intern(const Intern &copy);
		~Intern();

		Intern &operator=(const Intern &copy);

		// Functions
		AForm *makeForm(const std::string FormName, const std::string FormTarget);
};

#endif