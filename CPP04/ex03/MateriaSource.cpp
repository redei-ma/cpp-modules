#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		slots[i] = NULL;
	std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < 4; i++) {
		if (other.slots[i] != NULL)
			this->slots[i] = other.slots[i]->clone();
		else
			this->slots[i] = NULL;
	}
	std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other)
{
	if (this == &other)
		return (*this);
	for (int i = 0; i < 4; i++)
		delete slots[i];
	for (int i = 0; i < 4; i++) {
		if (other.slots[i] != NULL)
			this->slots[i] = other.slots[i]->clone();
		else
			this->slots[i] = NULL;
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		delete slots[i];
	std::cout << "MateriaSource destructor called" << std::endl;
}

static int	findSpace(AMateria **slots)
{
	for (int i = 0; i < 4; i++) {
		if (slots[i] == NULL)
			return (i);
	}
	return (-1);
}

void		MateriaSource::learnMateria(AMateria* m)
{
	int	pos = 0;

	if (m == NULL)
		return ;
	pos = findSpace(slots);
	if (pos != -1) {
		slots[pos] = m;
		std::cout << "Materia " << m->getType() << " learned" << std::endl;
	}
	else
		std::cout << "Slots are full" << std::endl;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++) {
		if (slots[i] != NULL && slots[i]->getType() == type)
			return (slots[i]->clone());
	}
	return (NULL);
}
