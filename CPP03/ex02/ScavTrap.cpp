#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	hitPoints = 100;
	energy = 50;
	attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	hitPoints = 100;
	energy = 50;
	attackDamage = 20;
	std::cout << "ScavTrap " << name << " was created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called for " << name << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "ScavTrap assignment operator called for " << name << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " is dying" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (hitPoints == 0) {
		std::cout << "ScavTrap " << name << " is dead and cannot attack!" << std::endl;
		return;
	}
	if (energy <= 0) {
		std::cout << "ScavTrap " << name << " has no energy to attack!" << std::endl;
		return;
	}

	energy--;
	std::cout << "ScavTrap " << name << " attacks " << target
			  << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode" << std::endl;
}
