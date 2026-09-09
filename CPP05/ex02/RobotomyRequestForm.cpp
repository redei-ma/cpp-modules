#include "RobotomyRequestForm.hpp"

bool	RobotomyRequestForm::seeded = false;

RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomy", 72, 45), target("") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("robotomy", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target) {}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other) {
		AForm::operator=(other);
		this->target = other.target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void	RobotomyRequestForm::executeAction()	const
{
	std::cout << "Brrrr... zzzzt... clang... " << std::endl;
	if (!seeded) {
		std::srand(std::time(0));
		seeded = true;
	}
	if (std::rand() % 2 == 0)
		std::cout << target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "The robotomy of " << target << " has failed" << std::endl;
}
