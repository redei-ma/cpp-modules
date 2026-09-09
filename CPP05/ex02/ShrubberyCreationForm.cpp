#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrubbery", 145, 137), target("") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("shrubbery", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target) {}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other) {
		AForm::operator=(other);
		this->target = other.target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::executeAction()	const
{
	std::string		fileName = target + "_shrubbery";
	std::ofstream	file;
	file.open(fileName.c_str());
	if (file.is_open()) {
		file	<< "	  /\\" << std::endl
				<< "     /  \\           /\\" << std::endl
				<< "    / /\\ \\   /\\    /  \\" << std::endl
				<< "   / ____ \\ /  \\  / /\\ \\" << std::endl
				<< "  /_/____\\_\\ /\\ \\/ ____ \\" << std::endl
				<< "      ||  / ____ \\/____\\_\\" << std::endl
				<< "      || /_/____\\_\\ ||" << std::endl
				<< "      ||     ||     ||" << std::endl
				<< "      ||     ||     ||" << std::endl;
		file.close();
	}
	else
		throw std::runtime_error("Could not open file");
}

/*
	  /\                    
     /  \           /\     
    / /\ \   /\    /  \   
   / ____ \ /  \  / /\ \  
  /_/____\_\ /\ \/ ____ \  
      ||  / ____ \/____\_\ 
      || /_/____\_\ ||         
      ||     ||     ||     
      ||     ||     ||     
*/
