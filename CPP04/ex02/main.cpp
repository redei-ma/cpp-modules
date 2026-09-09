#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

/*
** Animal class is now abstract due to pure virtual function makeSound() = 0
** Cannot instantiate Animal objects directly: new Animal() = compile error
** Can still use Animal* pointers for polymorphism: Animal* ptr = new Dog()
*/

int	main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;

	Animal* zoo[20];

	for (int i = 0; i < 20; i++) {
		if (i % 2 == 0)
			zoo[i] = new Dog();
		else
			zoo[i] = new Cat();
	}

	std::cout << "========== SOUND TEST ==========" << std::endl << std::endl;
	for (int i = 0; i < 10; i++)
		zoo[i]->makeSound();
	std::cout << std::endl << std::endl;

	std::cout << "========== BRAIN TEST ==========" << std::endl << std::endl;

	std::cout << "---------- DOG BRAIN ----------" << std::endl;
	Dog*	dog = new Dog();
	dog->setIdea("Woof, treats!");

	std::cout << "Dog thoughts: " << std::endl;
	dog->printIdeas();

	delete dog;
	std::cout << std::endl;

	std::cout << "---------- CAT BRAIN ----------" << std::endl;
	Cat*	cat = new Cat();
	cat->setIdea("Miao, treats!");

	std::cout << "Cat thoughts: " << std::endl;
	cat->printIdeas();

	delete cat;
	std::cout << std::endl;

	std::cout << "---------- ANIMAL BRAIN ----------" << std::endl;
	Dog* zooDog = static_cast<Dog*>(zoo[0]);
	zooDog->setIdea("Woof, treats");

	Cat* zooCat = static_cast<Cat*>(zoo[1]);
	zooCat->setIdea("Miao, treats");

	std::cout << "Zoo thoughts: " << std::endl;
	zooDog->printIdeas();
	zooCat->printIdeas();

	for (int i = 0; i < 20; i++)
		delete zoo[i];
	std::cout << std::endl;

	std::cout << "---------- COPY BRAIN ----------" << std::endl;
	Dog* dog1 = new Dog();
	dog1->setIdea("Woof, treats");

	Dog* dog2 = new Dog(*dog1);
	dog2->setIdea("Woof, bones");
	dog1->setIdea("Woof, toys");

	std::cout << "Dog1 thoughts: " << std::endl;
	dog1->printIdeas();
	std::cout << "Dog2 thoughts: " << std::endl;
	dog2->printIdeas();

	delete dog1;
	delete dog2;

	return (0);
}
