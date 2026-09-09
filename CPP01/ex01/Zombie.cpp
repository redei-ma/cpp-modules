#include "Zombie.hpp"

Zombie::Zombie()
{}

Zombie::~Zombie()
{
	std::cout << name << ": "
				<< "I'm dying"
				<< std::endl;
}

void Zombie::announce(void) const
{
	std::cout << name << ": "
				<< "BraiiiiiiinnnzzzZ.."
				<< std::endl;
}

void	Zombie::setName(const std::string myName)
{
	name = myName;
}
