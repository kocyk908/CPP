#include "Form.hpp"

Form::Form() : _name("default"), _isSigned(false), _gradeRequiredToSign(150), _gradeRequiredToExecute(150)
{
}

Form::Form(const std::string name, int gradeRequiredToSign, int gradeRequiredToExecute) : _name(name), _isSigned(false), _gradeRequiredToSign(gradeRequiredToSign), _gradeRequiredToExecute(gradeRequiredToExecute)
{
	if (gradeRequiredToSign < 1 || gradeRequiredToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeRequiredToSign > 150 || gradeRequiredToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &copy) : _name(copy._name), _isSigned(copy._isSigned), _gradeRequiredToSign(copy._gradeRequiredToSign), _gradeRequiredToExecute(copy._gradeRequiredToExecute)
{
	*this = copy;
}

Form::~Form()
{
}

Form &Form::operator=(const Form &copy)
{
	if (this != &copy)
		_isSigned = copy._isSigned;
	return (*this);
}

// Getters
const std::string &Form::getName() const
{
	return (_name);
}

const bool &Form::getIsSigned() const
{
	return (_isSigned);
}

const int &Form::getGradeRequiredToSign() const
{
	return (_gradeRequiredToSign);
}

const int &Form::getGradeRequiredToExecute() const
{
	return (_gradeRequiredToExecute);
}

// Functions

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeRequiredToSign)
	{
		_isSigned = false;
		throw GradeTooLowException();
	}
	else
	{
		_isSigned = true;
	}
}

// Exceptions

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "Form name: " << form.getName() << ", is signed: " << form.getIsSigned() << ", grade required to sign: " << form.getGradeRequiredToSign() << ", grade required to execute: " << form.getGradeRequiredToExecute() << std::endl;
	return (out);
}
