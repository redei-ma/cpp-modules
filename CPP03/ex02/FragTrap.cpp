#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	hitPoints = 100;
	energy = 100;
	attackDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	hitPoints = 100;
	energy = 100;
	attackDamage = 30;
	std::cout << "FragTrap " << name << " was created" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called for " << name << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "FragTrap assignment operator called for " << name << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " is dying" << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (hitPoints == 0) {
		std::cout << "FragTrap " << name << " is dead and cannot attack!" << std::endl;
		return;
	}
	if (energy <= 0) {
		std::cout << "FragTrap " << name << " has no energy to attack!" << std::endl;
		return;
	}

	energy--;
	std::cout << "FragTrap " << name << " attacks " << target
			  << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << " requests a positive high five!" << std::endl;
}
