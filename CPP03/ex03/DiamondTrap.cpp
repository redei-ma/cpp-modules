#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("_clap_name"), ScavTrap(), FragTrap(), name("")
{
	// ClapTrap is a virtual base, so these are one variable and cannot be read back from the parents
	this->hitPoints = 100;		// FragTrap
	this->energy = 50;			// ScavTrap
	this->attackDamage = 30;	// FragTrap
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name)
{
	// ClapTrap is a virtual base, so these are one variable and cannot be read back from the parents
	this->hitPoints = 100;		// FragTrap
	this->energy = 50;			// ScavTrap
	this->attackDamage = 30;	// FragTrap
	std::cout << "DiamondTrap " << name << " was created" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name)
{
	this->hitPoints = other.hitPoints;
	this->energy = other.energy;
	this->attackDamage = other.attackDamage;
	std::cout << "DiamondTrap copy constructor called for " << name << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other) {
		ScavTrap::operator=(other);
		FragTrap::operator=(other);
		this->name = other.name;
	}
	std::cout << "DiamondTrap assignment operator called" << std::endl;
	return (*this);
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "I am DiamondTrap " << this->name << " and my ClapTrap name is " << ClapTrap::name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << name << " is dying" << std::endl;
}
