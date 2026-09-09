#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class	HumanB
{
	private:
		std::string	name;
		Weapon*		weapon;

	public:
		HumanB(const std::string& myName);
		HumanB(const std::string& myName, Weapon& myWeapon);
		void	setWeapon(Weapon& myWeapon);
		void	attack();
		~HumanB();
};

#endif
