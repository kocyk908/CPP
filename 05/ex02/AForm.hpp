#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <fstream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeRequiredToSign;
		const int _gradeRequiredToExecute;
	
	public:
		AForm();
		AForm(const std::string name, int gradeRequiredToSign, int gradeRequiredToExecute);
		AForm(const AForm &copy);
		virtual ~AForm(); // abstract class

		AForm &operator=(const AForm &copy);

		// Getters
		const std::string	&getName() const;
		const bool			&getIsSigned() const;
		const int			&getGradeRequiredToSign() const;
		const int			&getGradeRequiredToExecute() const;

		// Functions
		void				beSigned(const Bureaucrat &bureaucrat);

		// EX02 functions
		void				isValidToExecute(const Bureaucrat &executor) const;
		virtual void		execute(const Bureaucrat &executor) = 0;

		// Exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		// Ex02 exceptions 
		class FormNotSignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif