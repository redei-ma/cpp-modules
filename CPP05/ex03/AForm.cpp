#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() :name("default"), isSigned(false), gradeToSign(1), gradeToExec(150) {}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExec) :name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExec(gradeToExec)
{
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
	else if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
}

AForm::AForm(const AForm& other) :name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec) {}

AForm&	AForm::operator=(const AForm& other)
{
	std::cout << "Form can't copy assignment" << std::endl;
	(void)other;
	return (*this);
}

AForm::~AForm() {}

std::string	AForm::getName()	const
{
	return (this->name);
}

bool	AForm::getIsSigned()	const
{
	return (this->isSigned);
}

int	AForm::getGradeToSign()	const
{
	return (this->gradeToSign);
}

int	AForm::getGradeToExec()	const
{
	return (this->gradeToExec);
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}

void	AForm::execute(Bureaucrat const & executor)	const
{
	if (!isSigned)
		throw FormNotSigned();
	if (executor.getGrade() > gradeToExec)
		throw GradeTooLowException();
	executeAction();
}

std::ostream&	operator<<(std::ostream& stream, const AForm& form)
{
	stream << "Form: " << form.getName()
		   << ", signed: " << (form.getIsSigned() ? "yes" : "no")
		   << ", grade to sign: " << form.getGradeToSign()
		   << ", grade to execute: " << form.getGradeToExec();
	return (stream);
}

AForm::GradeTooHighException::~GradeTooHighException() throw() {}

const char*	AForm::GradeTooHighException::what()	const throw()
{
	return ("Grade is too high");
}

AForm::GradeTooLowException::~GradeTooLowException() throw() {}

const char*	AForm::GradeTooLowException::what()	const throw()
{
	return ("Grade is too low");
}

AForm::FormNotSigned::~FormNotSigned() throw() {}

const char*	AForm::FormNotSigned::what()	const throw()
{
	return ("Form is not signed");
}
