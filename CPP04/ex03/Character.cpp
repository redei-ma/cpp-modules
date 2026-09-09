#include "Character.hpp"

Character::Character() :name("")
{
	for (int i = 0; i < 4; i++)
		slots[i] = NULL;
	for (int i = 0; i < 50; i++)
		unequipped[i] = NULL;
	std::cout << "Character default constructor called" << std::endl;
}

Character::Character(const std::string& name) :name(name)
{
	for (int i = 0; i < 4; i++)
		slots[i] = NULL;
	for (int i = 0; i < 50; i++)
		unequipped[i] = NULL;
	std::cout << "Character constructor called" << std::endl;
}

Character::Character(const Character &other) :name(other.name)
{
	for (int i = 0; i < 4; i++) {
		if (other.slots[i] != NULL)
			this->slots[i] = other.slots[i]->clone();
		else
			this->slots[i] = NULL;
	}

	for (int i = 0; i < 50; i++) {
		if (other.unequipped[i] != NULL)
			this->unequipped[i] = other.unequipped[i]->clone();
		else
			this->unequipped[i] = NULL;
	}
	std::cout << "Character copy constructor called" << std::endl;
}

Character&	Character::operator=(const Character& other)
{
	if (this == &other)
		return (*this);

	this->name = other.name;
	for (int i = 0; i < 4; i++)
		delete this->slots[i];
	for (int i = 0; i < 4; i++) {
		if (other.slots[i] != NULL)
			this->slots[i] = other.slots[i]->clone();
		else
			this->slots[i] = NULL;
	}

	for (int i = 0; i < 50; i++)
		delete this->unequipped[i];
	for (int i = 0; i < 50; i++) {
		if (other.unequipped[i] != NULL)
			this->unequipped[i] = other.unequipped[i]->clone();
		else
			this->unequipped[i] = NULL;
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++) {
		delete slots[i];
	}
	for (int i = 0; i < 50; i++) {
		delete unequipped[i];
	}
	std::cout << "Character destructor called" << std::endl;
}

std::string const & Character::getName() const
{
	return (name);
}

void	Character::equip(AMateria* m)
{
	if (m == NULL)
		return ;
	for (int i = 0; i < 4; i++) {
		if (slots[i] == NULL) {
			slots[i] = m;
			return ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || slots[idx] == NULL)
		return ;
	for (int i = 0; i < 50; i++) {
		if (unequipped[i] == NULL) {
			unequipped[i] = slots[idx];
			slots[idx] = NULL;
			return ;
		}
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx <= 3 && slots[idx] != NULL)
		slots[idx]->use(target);
}
