#include "AForm.hpp"

AForm::AForm() : _name("default"), _isSigned(false), _gradeRequiredToSign(150), _gradeRequiredToExecute(150)
{
}

AForm::AForm(const std::string name, int gradeRequiredToSign, int gradeRequiredToExecute) : _name(name), _isSigned(false), _gradeRequiredToSign(gradeRequiredToSign), _gradeRequiredToExecute(gradeRequiredToExecute)
{
	if (gradeRequiredToSign < 1 || gradeRequiredToExecute < 1)
		throw GradeTooHighException();
	else if (gradeRequiredToSign > 150 || gradeRequiredToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &copy) : _name(copy._name), _isSigned(copy._isSigned), _gradeRequiredToSign(copy._gradeRequiredToSign), _gradeRequiredToExecute(copy._gradeRequiredToExecute)
{
	*this = copy;
}

AForm::~AForm()
{
}

AForm &AForm::operator=(const AForm &copy)
{
	if (this != &copy)
		_isSigned = copy._isSigned;
	return (*this);
}

// Getters
const std::string &AForm::getName() const
{
	return (_name);
}

const bool &AForm::getIsSigned() const
{
	return (_isSigned);
}

const int &AForm::getGradeRequiredToSign() const
{
	return (_gradeRequiredToSign);
}

const int &AForm::getGradeRequiredToExecute() const
{
	return (_gradeRequiredToExecute);
}

// Functions
void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeRequiredToSign)
	{
		_isSigned = false;
		throw AForm::GradeTooLowException();
	}
	else
	{
		_isSigned = true;
	}
}

// EX02 functions

void AForm::isValidToExecute(const Bureaucrat &executor) const
{
	if (this->getIsSigned() == false)
		throw AForm::FormNotSignedException();
	else if (this->getGradeRequiredToExecute() < executor.getGrade())
		throw AForm::GradeTooLowException();
}

// Exceptions
const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

	// Ex02 exceptions
const char *AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed");
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	out << "Form name: " << form.getName() << ", is signed: " << form.getIsSigned() << ", grade required to sign: " << form.getGradeRequiredToSign() << ", grade required to execute: " << form.getGradeRequiredToExecute() << std::endl;
	return (out);
}
