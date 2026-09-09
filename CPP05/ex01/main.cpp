#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	// Test 1: Normal Form creation
	std::cout << "Test 1: Normal Form creation" << std::endl;
	try {
		Form	permit("Building Permit", 50, 25);
		std::cout << permit << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 2: Form with grade too high (< 1)
	std::cout << "Test 2: Form with grade too high (0)" << std::endl;
	try {
		Form	invalid("Invalid Form", 0, 50);
		std::cout << invalid << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 3: Form with grade too low (> 150)
	std::cout << "Test 3: Form with grade too low (151)" << std::endl;
	try {
		Form	invalid("Invalid Form", 50, 151);
		std::cout << invalid << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 4: Bureaucrat signing a form (successful)
	std::cout << "Test 4: Bureaucrat signing form (successful)" << std::endl;
	try {
		Bureaucrat	alice("Alice", 30);
		Form		vacation("Vacation Request", 50, 25);

		std::cout << "Before signing:" << std::endl;
		std::cout << alice << std::endl;
		std::cout << vacation << std::endl;

		alice.signForm(vacation);

		std::cout << "After signing attempt:" << std::endl;
		std::cout << vacation << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 5: Bureaucrat signing a form (grade too low)
	std::cout << "Test 5: Bureaucrat signing form (grade too low)" << std::endl;
	try {
		Bureaucrat	bob("Bob", 100);
		Form		important("Important Document", 20, 10);

		std::cout << "Before signing:" << std::endl;
		std::cout << bob << std::endl;
		std::cout << important << std::endl;

		bob.signForm(important);

		std::cout << "After signing attempt:" << std::endl;
		std::cout << important << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 6: Multiple forms with same bureaucrat
	std::cout << "Test 6: Multiple forms with same bureaucrat" << std::endl;
	try {
		Bureaucrat	charlie("Charlie", 25);
		Form		easy("Easy Form", 100, 50);
		Form		medium("Medium Form", 50, 25);
		Form		hard("Hard Form", 10, 5);

		std::cout << "Bureaucrat: " << charlie << std::endl;
		std::cout << "Forms:" << std::endl;
		std::cout << easy << std::endl;
		std::cout << medium << std::endl;
		std::cout << hard << std::endl;

		std::cout << "\nSigning attempts:" << std::endl;
		charlie.signForm(easy);
		charlie.signForm(medium);
		charlie.signForm(hard);

		std::cout << "\nFinal state:" << std::endl;
		std::cout << easy << std::endl;
		std::cout << medium << std::endl;
		std::cout << hard << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	return 0;
}
