#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const	std::string _name;
		int		_grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat();

		Bureaucrat &operator=(const Bureaucrat &copy);

		// Getters
		const std::string &getName() const;
		const int &getGrade() const;

		// Functions
		void incrementGrade();
		void decrementGrade();
		// EX01 functions
		void signForm(AForm &form);
		// EX02 functions
		void executeForm(AForm &form);

		// Exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif