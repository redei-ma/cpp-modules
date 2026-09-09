#include "Cat.hpp"

Cat::Cat() :Animal()
{
	type = "Cat";
	brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) :Animal(other)
{
	brain = new Brain(*other.brain);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat& other)
{
	if (this == &other)
		return (*this);
	delete brain;
	brain = new Brain(*other.brain);
	Animal::operator=(other);
	return (*this);
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound()	const
{
	std::cout << "Meow!" << std::endl;
}

void	Cat::setIdea(std::string idea)
{
	brain->setIdea(idea);
}

void	Cat::printIdeas()	const
{
	brain->printIdeas();
}
