#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() :name("default"), grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) :name(name), grade(grade)
{
	if (this->getGrade() > 150)
		throw GradeTooLowException();
	else if (this->getGrade() < 1)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) :name(other.name), grade(other.grade) {}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Attribute name is const, so it cannot be copied" << std::endl;
	if (this != &other)
		grade = other.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string	Bureaucrat::getName()	const
{
	return (this->name);
}

int	Bureaucrat::getGrade()	const
{
	return (this->grade);
}

void	Bureaucrat::incrementGrade()
{
	if (grade < 2)
		throw GradeTooHighException();
	grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (grade > 149)
		throw GradeTooLowException();
	grade++;
}

void	Bureaucrat::signForm(Form& form)	const
{
	try {
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream&	operator<<(std::ostream& stream, const Bureaucrat& me)
{
	stream << me.getName() << ", bureaucrat grade " << me.getGrade() << ".";
	return (stream);
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

const char*	Bureaucrat::GradeTooHighException::what()	const throw()
{
	return ("Grade is too high");
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

const char*	Bureaucrat::GradeTooLowException::what()	const throw()
{
	return ("Grade is too low");
}
