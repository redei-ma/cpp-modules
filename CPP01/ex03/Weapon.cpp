#include "Weapon.hpp"

Weapon::Weapon(const std::string weaponType) :type(weaponType)
{}

Weapon::Weapon()
{}

Weapon::~Weapon()
{}

const std::string&	Weapon::getType() const
{
	return (type);
}

void	Weapon::setType(const std::string weaponType)
{
	type = weaponType;
}
