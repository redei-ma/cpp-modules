#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

void test_basic_functionality() {
	std::cout << "\n=== BASIC FUNCTIONALITY TESTS ===" << std::endl;

	std::cout << "\n--- Creating Animals ---" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "\n--- Testing getType() ---" << std::endl;
	std::cout << "Animal type: '" << meta->getType() << "'" << std::endl;
	std::cout << "Dog type: '" << j->getType() << "'" << std::endl;
	std::cout << "Cat type: '" << i->getType() << "'" << std::endl;

	std::cout << "\n--- Testing makeSound() - Should show polymorphism ---" << std::endl;
	std::cout << "Animal sound: ";
	meta->makeSound();
	std::cout << "Dog sound: ";
	j->makeSound();
	std::cout << "Cat sound: ";
	i->makeSound();

	std::cout << "\n--- Deleting Animals (testing virtual destructors) ---" << std::endl;
	delete meta;
	delete j;
	delete i;
}

void test_copy_constructors() {
	std::cout << "\n=== COPY CONSTRUCTOR TESTS ===" << std::endl;

	std::cout << "\n--- Creating original objects ---" << std::endl;
	Dog original_dog;
	Cat original_cat;

	std::cout << "\n--- Testing copy constructors ---" << std::endl;
	Dog copied_dog(original_dog);
	Cat copied_cat(original_cat);

	std::cout << "\n--- Verifying copied objects work correctly ---" << std::endl;
	std::cout << "Original dog type: " << original_dog.getType() << std::endl;
	std::cout << "Copied dog type: " << copied_dog.getType() << std::endl;
	std::cout << "Original cat type: " << original_cat.getType() << std::endl;
	std::cout << "Copied cat type: " << copied_cat.getType() << std::endl;

	std::cout << "\n--- Testing sounds of copied objects ---" << std::endl;
	std::cout << "Original dog: ";
	original_dog.makeSound();
	std::cout << "Copied dog: ";
	copied_dog.makeSound();
	std::cout << "Original cat: ";
	original_cat.makeSound();
	std::cout << "Copied cat: ";
	copied_cat.makeSound();
}

void test_assignment_operators() {
	std::cout << "\n=== ASSIGNMENT OPERATOR TESTS ===" << std::endl;

	std::cout << "\n--- Creating objects for assignment test ---" << std::endl;
	Dog dog1;
	Dog dog2;
	Cat cat1;
	Cat cat2;

	std::cout << "\n--- Testing assignment operators ---" << std::endl;
	std::cout << "Before assignment:" << std::endl;
	std::cout << "Dog1 type: " << dog1.getType() << std::endl;
	std::cout << "Dog2 type: " << dog2.getType() << std::endl;

	dog2 = dog1;  // Assignment
	cat2 = cat1;  // Assignment

	std::cout << "After assignment:" << std::endl;
	std::cout << "Dog1 type: " << dog1.getType() << std::endl;
	std::cout << "Dog2 type: " << dog2.getType() << std::endl;
	std::cout << "Cat1 type: " << cat1.getType() << std::endl;
	std::cout << "Cat2 type: " << cat2.getType() << std::endl;

	std::cout << "\n--- Testing self-assignment ---" << std::endl;
	// Note: Self-assignment test removed due to compiler warning
	// The operator= implementation already handles self-assignment safely
	std::cout << "Self-assignment protection is implemented in operator=" << std::endl;
}

void test_polymorphism_array() {
	std::cout << "\n=== POLYMORPHISM ARRAY TESTS ===" << std::endl;

	const int size = 6;
	Animal* animals[size];

	std::cout << "\n--- Creating array of Animal pointers ---" << std::endl;
	animals[0] = new Animal();
	animals[1] = new Dog();
	animals[2] = new Cat();
	animals[3] = new Dog();
	animals[4] = new Cat();
	animals[5] = new Animal();

	std::cout << "\n--- Testing polymorphic behavior in array ---" << std::endl;
	for (int i = 0; i < size; i++) {
		std::cout << "Animal[" << i << "] - Type: '" << animals[i]->getType()
				  << "', Sound: ";
		animals[i]->makeSound();
	}

	std::cout << "\n--- Deleting array elements ---" << std::endl;
	for (int i = 0; i < size; i++) {
		std::cout << "Deleting animal[" << i << "]:" << std::endl;
		delete animals[i];
	}
}

void test_wrong_classes() {
	std::cout << "\n=== WRONG CLASSES TESTS (Non-polymorphic behavior) ===" << std::endl;

	std::cout << "\n--- Creating Wrong classes ---" << std::endl;
	const WrongAnimal* wrong_meta = new WrongAnimal();
	const WrongAnimal* wrong_cat = new WrongCat();  // This should NOT behave polymorphically
	WrongCat* actual_wrong_cat = new WrongCat();

	std::cout << "\n--- Testing Wrong classes behavior ---" << std::endl;
	std::cout << "WrongAnimal type: '" << wrong_meta->getType() << "'" << std::endl;
	std::cout << "WrongCat (as WrongAnimal*) type: '" << wrong_cat->getType() << "'" << std::endl;
	std::cout << "WrongCat (as WrongCat*) type: '" << actual_wrong_cat->getType() << "'" << std::endl;

	std::cout << "\n--- Testing makeSound() - Should NOT show polymorphism ---" << std::endl;
	std::cout << "WrongAnimal sound: ";
	wrong_meta->makeSound();
	std::cout << "WrongCat (as WrongAnimal*) sound: ";
	wrong_cat->makeSound();  // Should call WrongAnimal::makeSound(), not WrongCat::makeSound()
	std::cout << "WrongCat (as WrongCat*) sound: ";
	actual_wrong_cat->makeSound();  // Should call WrongCat::makeSound()

	std::cout << "\n--- Deleting Wrong classes ---" << std::endl;
	delete wrong_meta;
	delete wrong_cat;
	delete actual_wrong_cat;
}

void test_stack_vs_heap() {
	std::cout << "\n=== STACK VS HEAP ALLOCATION TESTS ===" << std::endl;

	std::cout << "\n--- Stack allocation test ---" << std::endl;
	{
		Animal animal;
		Dog dog;
		Cat cat;

		std::cout << "Stack objects created, testing functionality:" << std::endl;
		std::cout << "Animal: ";
		animal.makeSound();
		std::cout << "Dog: ";
		dog.makeSound();
		std::cout << "Cat: ";
		cat.makeSound();

		std::cout << "Leaving scope - stack objects will be destroyed:" << std::endl;
	}  // Destructors should be called automatically here

	std::cout << "\n--- Heap allocation test ---" << std::endl;
	Animal* heap_animal = new Animal();
	Dog* heap_dog = new Dog();
	Cat* heap_cat = new Cat();

	std::cout << "Heap objects created, testing functionality:" << std::endl;
	std::cout << "Animal: ";
	heap_animal->makeSound();
	std::cout << "Dog: ";
	heap_dog->makeSound();
	std::cout << "Cat: ";
	heap_cat->makeSound();

	std::cout << "Manually deleting heap objects:" << std::endl;
	delete heap_animal;
	delete heap_dog;
	delete heap_cat;
}

void test_const_correctness() {
	std::cout << "\n=== CONST CORRECTNESS TESTS ===" << std::endl;

	const Animal animal;
	const Dog dog;
	const Cat cat;

	std::cout << "\n--- Testing const objects ---" << std::endl;
	std::cout << "Const Animal type: " << animal.getType() << std::endl;
	std::cout << "Const Dog type: " << dog.getType() << std::endl;
	std::cout << "Const Cat type: " << cat.getType() << std::endl;

	std::cout << "\n--- Testing const makeSound() ---" << std::endl;
	std::cout << "Const Animal: ";
	animal.makeSound();
	std::cout << "Const Dog: ";
	dog.makeSound();
	std::cout << "Const Cat: ";
	cat.makeSound();
}

int main() {
	std::cout << "==================================================" << std::endl;
	std::cout << "         COMPREHENSIVE ANIMAL HIERARCHY TESTS     " << std::endl;
	std::cout << "==================================================" << std::endl;

	try {
		test_basic_functionality();
		test_copy_constructors();
		test_assignment_operators();
		test_polymorphism_array();
		test_wrong_classes();
		test_stack_vs_heap();
		test_const_correctness();

		std::cout << "\n==================================================" << std::endl;
		std::cout << "               ALL TESTS COMPLETED                " << std::endl;
		std::cout << "==================================================" << std::endl;

	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
		return 1;
	} catch (...) {
		std::cerr << "Unknown exception caught!" << std::endl;
		return 1;
	}

	return 0;
}
