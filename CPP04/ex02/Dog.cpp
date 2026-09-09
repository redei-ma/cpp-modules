#include "Dog.hpp"

Dog::Dog() :Animal()
{
	type = "Dog";
	brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) :Animal(other)
{
	brain = new Brain(*other.brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog&	Dog::operator=(const Dog& other)
{
	if (this == &other)
		return (*this);
	delete brain;
	brain = new Brain(*other.brain);
	Animal::operator=(other);
	return (*this);
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound()	const
{
	std::cout << "Woof!" << std::endl;
}

void	Dog::setIdea(std::string idea)
{
	brain->setIdea(idea);
}

void	Dog::printIdeas()	const
{
	brain->printIdeas();
}
