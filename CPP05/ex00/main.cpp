#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	// Test 1: Normal creation
	std::cout << "Test 1: Normal creation" << std::endl;
	try {
		Bureaucrat bob("Bob", 75);
		std::cout << bob << std::endl << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl << std::endl;
	}

	// Test 2: Grade too high (< 1)
	std::cout << "Test 2: Grade too high (0)" << std::endl;
	try {
		Bureaucrat invalid("Invalid", 0);
		std::cout << invalid << std::endl << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl << std::endl;
	}

	// Test 3: Grade too low (> 150)
	std::cout << "Test 3: Grade too low (151)" << std::endl;
	try {
		Bureaucrat invalid("Invalid", 151);
		std::cout << invalid << std::endl << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl << std::endl;
	}

	// Test 4: Increment grade
	std::cout << "Test 4: Increment grade" << std::endl;
	try {
		Bureaucrat alice("Alice", 5);
		std::cout << "Before: " << alice << std::endl;
		alice.incrementGrade();
		std::cout << "After increment: " << alice << std::endl << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl << std::endl;
	}

	// Test 5: Decrement grade
	std::cout << "Test 5: Decrement grade" << std::endl;
	try {
		Bureaucrat charlie("Charlie", 145);
		std::cout << "Before: " << charlie << std::endl;
		charlie.decrementGrade();
		std::cout << "After decrement: " << charlie << std::endl << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl << std::endl;
	}

	// Test 6: Increment beyond limit (grade 1 -> 0)
	std::cout << "Test 6: Increment beyond limit" << std::endl;
	try {
		Bureaucrat dave("Dave", 1);
		std::cout << "Before: " << dave << std::endl;
		dave.incrementGrade();
		std::cout << "After increment: " << dave << std::endl << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl << std::endl;
	}

	// Test 7: Decrement beyond limit (grade 150 -> 151)
	std::cout << "Test 7: Decrement beyond limit" << std::endl;
	try {
		Bureaucrat eve("Eve", 150);
		std::cout << "Before: " << eve << std::endl;
		eve.decrementGrade();
		std::cout << "After decrement: " << eve << std::endl << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl << std::endl;
	}

	// Test 8: Copy constructor and assignment operator
	std::cout << "Test 8: Copy constructor and assignment" << std::endl;
	try {
		Bureaucrat original("Original", 50);
		std::cout << "Original: " << original << std::endl;

		Bureaucrat copy(original);
		std::cout << "Copy: " << copy << std::endl;

		Bureaucrat assigned("Temp", 100);
		assigned = original;
		std::cout << "Assigned: " << assigned << std::endl << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl << std::endl;
	}

	return 0;
}
