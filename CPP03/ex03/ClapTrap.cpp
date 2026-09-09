#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :name(""), hitPoints(10), energy(10), attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) :name(name), hitPoints(10), energy(10), attackDamage(0)
{
	std::cout << "ClapTrap " << name << " was created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name), hitPoints(other.hitPoints), energy(other.energy), attackDamage(other.attackDamage)
{
	std::cout << "ClapTrap copy constructor called for " << name << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other) {
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energy = other.energy;
		this->attackDamage = other.attackDamage;
	}
	std::cout << "ClapTrap assignment operator called for " << name << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " is dying" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (hitPoints == 0) {
		std::cout << "ClapTrap " << name << " is dead and cannot attack!" << std::endl;
		return;
	}
	if (energy <= 0) {
		std::cout << "ClapTrap " << name << " has no energy to attack!" << std::endl;
		return;
	}

	energy--;
	std::cout << "ClapTrap "  << name << " attacks " << target
				<< ", causing " << attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints == 0) {
		std::cout << "ClapTrap " << name << " is already dead!" << std::endl;
		return;
	}

	if (amount >= hitPoints)
		hitPoints = 0;
	else
		hitPoints -= amount;

	std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;

	if (hitPoints == 0)
		std::cout << "ClapTrap " << name << " has died!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints == 0) {
		std::cout << "ClapTrap " << name << " is dead and cannot be repaired!" << std::endl;
		return;
	}
	if (energy <= 0) {
		std::cout << "ClapTrap " << name << " has no energy to repair!" << std::endl;
		return;
	}

	energy--;
	hitPoints += amount;
	std::cout << "ClapTrap "  << name << " is being repaired for " << amount << " hit points" << std::endl;
}
