#include "HumanB.hpp"

HumanB::HumanB(const std::string& myName) :name(myName), weapon(NULL)
{}

HumanB::HumanB(const std::string& myName, Weapon& myWeapon) :name(myName), weapon(&myWeapon)
{}

HumanB::~HumanB()
{}

void	HumanB::setWeapon(Weapon& myWeapon)
{
	weapon = &myWeapon;
}

void	HumanB::attack()
{
	if (weapon) {
		std::cout << name << " attacks with their "
					<< (*weapon).getType() << std::endl;
	}
	else
		std::cout << name << " has no weapon!" << std::endl;
}
