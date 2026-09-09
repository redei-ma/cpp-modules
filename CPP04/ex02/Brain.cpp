#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		ideas[i] = "";
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
	if (this == &other)
		return (*this);
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "I'm losing brain function" << std::endl;
}

void	Brain::setIdea(std::string idea)
{
	if (idea.empty())
		return ;
	for (int i = 0; i < 100; i++) {
		if (ideas[i].empty()) {
			ideas[i] = idea;
			return ;
		}
		else if (i == 99)
			std::cout << "My brain is full" << std::endl;
	}
}

void	Brain::printIdeas() const
{
	for (int i = 0; i < 100 && !ideas[i].empty(); i++)
		std::cout << ideas[i] << std::endl;
}
