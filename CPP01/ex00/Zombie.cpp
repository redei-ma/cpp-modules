#include "Zombie.hpp"

Zombie::Zombie()
{}

Zombie::Zombie(const std::string zombieName) : name(zombieName)
{}

Zombie::~Zombie()
{
	std::cout << name << ": "
				<< "I'm dying"
				<< std::endl;
}

void Zombie::announce(void)
{
	std::cout << name << ": "
				<< "BraiiiiiiinnnzzzZ.."
				<< std::endl;
}
