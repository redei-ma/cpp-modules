#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie* myCreation = newZombie(name);

	myCreation->announce();
	delete myCreation;
}
