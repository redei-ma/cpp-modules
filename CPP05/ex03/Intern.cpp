#include "Intern.hpp"

const std::string	Intern::forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};

Intern::Intern() {}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern&	Intern::operator=(const Intern& other)
{
	(void)other;
	return (*this);
}

Intern::~Intern() {}

AForm*	Intern::makeForm(const std::string& formName, const std::string& target)	const
{
	if (formName.empty() || target.empty())
		throw std::invalid_argument("Invalid argument");
	for (int i = 0; i < 3; i++) {
		if (forms[i] == formName) {
			std::cout << "Intern creates " << formName << std::endl;
			switch (i) {
				case (0):
					return (new PresidentialPardonForm(target));
				case (1):
					return (new RobotomyRequestForm(target));
				case (2):
					return (new ShrubberyCreationForm(target));
			}
		}
	}
	throw FormNotFound();
}

Intern::FormNotFound::~FormNotFound() throw() {}

const char*	Intern::FormNotFound::what()	const throw()
{
	return ("Form not found");
}
