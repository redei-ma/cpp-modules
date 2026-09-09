#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	// Test 1: Bureaucrat with high enough grade to sign and execute all forms
	std::cout << "Test 1: High-grade bureaucrat (grade 1) - should succeed all" << std::endl;
	try {
		Bureaucrat president("President", 1);
		PresidentialPardonForm presidential("Criminal");
		RobotomyRequestForm robotomy("Patient");
		ShrubberyCreationForm shrubbery("garden");

		std::cout << "Bureaucrat: " << president << std::endl;
		std::cout << "\n--- Signing Forms ---" << std::endl;
		president.signForm(presidential);
		president.signForm(robotomy);
		president.signForm(shrubbery);

		std::cout << "\n--- Executing Forms ---" << std::endl;
		president.executeForm(presidential);
		president.executeForm(robotomy);
		president.executeForm(shrubbery);
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 2: Medium grade bureaucrat - can sign some but not execute presidential
	std::cout << "Test 2: Medium-grade bureaucrat (grade 50) - mixed results" << std::endl;
	try {
		Bureaucrat manager("Manager", 50);
		PresidentialPardonForm presidential("VIP");
		RobotomyRequestForm robotomy("Target");
		ShrubberyCreationForm shrubbery("office");

		std::cout << "Bureaucrat: " << manager << std::endl;
		std::cout << "\n--- Signing Forms ---" << std::endl;
		manager.signForm(presidential);  // Should fail - needs grade 25
		manager.signForm(robotomy);      // Should fail - needs grade 72
		manager.signForm(shrubbery);     // Should succeed - needs grade 145

		std::cout << "\n--- Executing Forms ---" << std::endl;
		manager.executeForm(presidential);  // Should fail - not signed
		manager.executeForm(robotomy);      // Should fail - not signed
		manager.executeForm(shrubbery);     // Should succeed
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 3: Testing robotomy randomness (multiple attempts)
	std::cout << "Test 3: Testing robotomy randomness (multiple attempts)" << std::endl;
	try {
		Bureaucrat scientist("Scientist", 1);

		for (int i = 1; i <= 5; i++) {
			RobotomyRequestForm robotomy("Subject");
			std::cout << "\n--- Attempt " << i << " ---" << std::endl;
			scientist.signForm(robotomy);
			scientist.executeForm(robotomy);
		}
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 4: Edge cases - exact grade requirements
	std::cout << "Test 4: Edge cases - exact grade requirements" << std::endl;
	try {
		// Presidential form: sign 25, exec 5
		Bureaucrat signer("Signer", 25);
		Bureaucrat executor("Executor", 5);
		PresidentialPardonForm presidential("Edge Case");

		std::cout << "Testing exact grade requirements for Presidential form:" << std::endl;
		std::cout << "Signer: " << signer << std::endl;
		std::cout << "Executor: " << executor << std::endl;

		signer.signForm(presidential);    // Should succeed
		signer.executeForm(presidential); // Should fail - grade 25 > exec requirement 5
		executor.executeForm(presidential); // Should succeed
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	return 0;
}
