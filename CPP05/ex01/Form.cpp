#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() :name("default"), isSigned(false), gradeToSign(1), gradeToExec(150) {}

Form::Form(const std::string& name, int gradeToSign, int gradeToExec) :name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExec(gradeToExec)
{
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
	else if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
}

Form::Form(const Form& other) :name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec) {}

Form&	Form::operator=(const Form& other)
{
	std::cout << "Form can't copy assignment" << std::endl;
	(void)other;
	return (*this);
}

Form::~Form() {}

std::string	Form::getName()	const
{
	return (this->name);
}

bool	Form::getIsSigned()	const
{
	return (this->isSigned);
}

int	Form::getGradeToSign()	const
{
	return (this->gradeToSign);
}

int	Form::getGradeToExec()	const
{
	return (this->gradeToExec);
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}

std::ostream&	operator<<(std::ostream& stream, const Form& form)
{
	stream << "Form: " << form.getName()
		   << ", signed: " << (form.getIsSigned() ? "yes" : "no")
		   << ", grade to sign: " << form.getGradeToSign()
		   << ", grade to execute: " << form.getGradeToExec();
	return (stream);
}

Form::GradeTooHighException::~GradeTooHighException() throw() {}

const char*	Form::GradeTooHighException::what()	const throw()
{
	return ("Grade is too high");
}

Form::GradeTooLowException::~GradeTooLowException() throw() {}

const char*	Form::GradeTooLowException::what()	const throw()
{
	return ("Grade is too low");
}
