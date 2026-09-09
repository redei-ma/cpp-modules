#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class	Zombie
{
	private:
		std::string	name;

	public:
		Zombie();
		void	announce(void) const;
		void	setName(const std::string name);
		~Zombie();
};

Zombie*	zombieHorde(int N, std::string myName);

#endif
