#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class	HumanA
{
	private:
		std::string	name;
		Weapon&		weapon;
		HumanA();

	public:
		HumanA(const std::string& myName, Weapon& myWeapon);
		void	attack();
		~HumanA();
};

#endif
