#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	// Test 1: Creating valid forms
	std::cout << "Test 1: Creating valid forms" << std::endl;
	try {
		Intern intern;
		AForm* form1 = intern.makeForm("presidential pardon", "Alice");
		AForm* form2 = intern.makeForm("robotomy request", "Bob");
		AForm* form3 = intern.makeForm("shrubbery creation", "garden");

		std::cout << "Created forms:" << std::endl;
		if (form1) std::cout << *form1 << std::endl;
		if (form2) std::cout << *form2 << std::endl;
		if (form3) std::cout << *form3 << std::endl;

		delete form1;
		delete form2;
		delete form3;
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 2: Testing invalid form names
	std::cout << "Test 2: Testing invalid form names" << std::endl;
	try {
		Intern intern;
		AForm* invalidForm = intern.makeForm("InvalidForm", "target");

		if (invalidForm) {
			std::cerr << "ERROR: Should not have created form!" << std::endl;
			delete invalidForm;
		}
	}
	catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 3: Testing forms functionality after creation
	std::cout << "Test 3: Testing forms functionality after creation" << std::endl;
	try {
		Intern intern;
		Bureaucrat boss("Boss", 1);

		AForm* presidential = intern.makeForm("presidential pardon", "Criminal");
		if (presidential) {
			boss.signForm(*presidential);
			boss.executeForm(*presidential);
			delete presidential;
		}

		std::cout << std::endl;

		// Create and test Robotomy form
		AForm* robotomy = intern.makeForm("robotomy request", "Patient");
		if (robotomy) {
			boss.signForm(*robotomy);
			boss.executeForm(*robotomy);
			delete robotomy;
		}

		std::cout << std::endl;

		// Create and test Shrubbery form
		AForm* shrubbery = intern.makeForm("shrubbery creation", "office");
		if (shrubbery) {
			boss.signForm(*shrubbery);
			boss.executeForm(*shrubbery);
			delete shrubbery;
		}
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 4: Testing Intern copy constructor and assignment
	std::cout << "Test 4: Testing Intern copy and assignment" << std::endl;
	try {
		Intern intern1;
		Intern intern2(intern1);  // Copy constructor
		Intern intern3;
		intern3 = intern1;        // Assignment operator

		std::cout << "Testing that all interns work the same way:" << std::endl;

		AForm* form1 = intern1.makeForm("presidential pardon", "Target1");
		AForm* form2 = intern2.makeForm("robotomy request", "Target2");
		AForm* form3 = intern3.makeForm("shrubbery creation", "Target3");

		if (form1) std::cout << *form1 << std::endl;
		if (form2) std::cout << *form2 << std::endl;
		if (form3) std::cout << *form3 << std::endl;

		// Clean up
		delete form1;
		delete form2;
		delete form3;
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 5: Edge case - empty strings
	std::cout << "Test 5: Edge case - empty strings" << std::endl;
	try {
		Intern intern;
		AForm* form1 = intern.makeForm("", "target");
		AForm* form2 = intern.makeForm("presidential pardon", "");

		if (form1) {
			std::cout << "Created form with empty name: " << *form1 << std::endl;
			delete form1;
		}
		if (form2) {
			std::cout << "Created form with empty target: " << *form2 << std::endl;
			delete form2;
		}
	}
	catch (std::exception& e) {
		std::cerr << "Exception with empty strings: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	return 0;
}
