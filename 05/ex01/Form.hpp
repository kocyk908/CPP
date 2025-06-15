#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeRequiredToSign;
		const int _gradeRequiredToExecute;
	
	public:
		Form();
		Form(const std::string name, int gradeRequiredToSign, int gradeRequiredToExecute);
		Form(const Form &copy);
		~Form();
		
		Form &operator=(const Form &copy);

		// Getters
		const std::string &getName() const;
		const bool &getIsSigned() const;
		const int &getGradeRequiredToSign() const;
		const int &getGradeRequiredToExecute() const;

		// Functions
		void beSigned(const Bureaucrat &bureaucrat);

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

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif