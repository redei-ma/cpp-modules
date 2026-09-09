#include "Zombie.hpp"
#include <sstream>

static std::string	intToString(int n)
{
	std::ostringstream ss;
	ss << n;
	return (ss.str());
}

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie*	horde = new Zombie[N];

	for (int i = 0; i < N; i++)
		horde[i].setName(name + intToString(i));
	return (horde);
}
