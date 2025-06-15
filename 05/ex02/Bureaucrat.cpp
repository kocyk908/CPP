#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{
	*this = copy;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	if (this != &copy)
		_grade = copy._grade;
	return (*this);
}

// Getters

const std::string &Bureaucrat::getName() const
{
	return (_name);
}

const int &Bureaucrat::getGrade() const
{
	return (_grade);
}

// Functions

void Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

// EX01 functions

void Bureaucrat::signForm(AForm &form)
{
    if (form.getGradeRequiredToExecute() < _grade)
	{
        std::cout << _name << " cannot sign " << form.getName() << " because grade is too low" << std::endl;
    }
	else
	{
		form.beSigned(*this);
        std::cout << _name << " signs " << form.getName() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm &form)
{
	try
	{
		form.isValidToExecute(*this);
		form.execute(*this);
		std::cout << _name << " executes " << form.getName() << std::endl;
	}
	catch (const AForm::FormNotSignedException &e)
	{
		std::cout << _name << " cannot execute " << form.getName() << " because: " << e.what() << std::endl;
	}
	catch (const AForm::GradeTooLowException &e)
	{
		std::cout << _name << " cannot execute " << form.getName() << " because: " << e.what() << std::endl;
	}
}

// Exceptions

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}


std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << "Bureaucrat named: " << bureaucrat.getName() << " with grade " << bureaucrat.getGrade() << std::endl;
	return (out);
}