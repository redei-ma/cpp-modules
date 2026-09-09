#include "HumanA.hpp"

HumanA::HumanA(const std::string& myName, Weapon& myWeapon) :name(myName), weapon(myWeapon)
{}

HumanA::~HumanA()
{}

void	HumanA::attack()
{
	std::cout << name << " attacks with their "
				<< weapon.getType() << std::endl;
}
