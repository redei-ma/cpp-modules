#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

/*
** Interface-based system test
** Testing MateriaSource learning, Character equipment, and Materia usage
*/
int main()
{
	std::cout << "========== BASIC INTERFACE TEST ==========" << std::endl;

	// Create materia source and learn some materias
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << std::endl;

	// Create characters
	ICharacter* alice = new Character("Alice");
	ICharacter* bob = new Character("Bob");

	std::cout << std::endl << "========== EQUIPPING MATERIAS ==========" << std::endl;

	// Create and equip materias
	AMateria* ice = src->createMateria("ice");
	AMateria* cure = src->createMateria("cure");
	AMateria* unknown = src->createMateria("fire"); // Should return NULL

	alice->equip(ice);
	alice->equip(cure);
	alice->equip(unknown); // Should handle NULL gracefully

	std::cout << std::endl << "========== USING MATERIAS ==========" << std::endl;

	// Use equipped materias
	std::cout << "Alice uses materias on Bob:" << std::endl;
	alice->use(0, *bob); // Ice
	alice->use(1, *bob); // Cure
	alice->use(2, *bob); // Empty slot
	alice->use(5, *bob); // Invalid index

	std::cout << std::endl << "========== UNEQUIP TEST ==========" << std::endl;

	// Test unequip
	alice->unequip(0); // Unequip ice
	alice->use(0, *bob); // Should do nothing

	std::cout << std::endl << "========== COPY TEST ==========" << std::endl;

	// Test character copying with equipped materias
	Character* charlie = new Character("Charlie");
	charlie->equip(src->createMateria("cure"));

	Character* david = new Character(*charlie); // Copy constructor

	std::cout << "Original Charlie uses materia:" << std::endl;
	charlie->use(0, *bob);

	std::cout << "Copied David uses materia:" << std::endl;
	david->use(0, *bob);

	std::cout << std::endl << "========== MATERIA SOURCE COPY ==========" << std::endl;

	// Test MateriaSource copying
	MateriaSource* src2 = new MateriaSource();
	src2->learnMateria(new Cure());

	MateriaSource* src3 = new MateriaSource(*src2); // Copy constructor

	AMateria* cure1 = src2->createMateria("cure");
	AMateria* cure2 = src3->createMateria("cure");

	std::cout << "Original source creates: ";
	if (cure1) std::cout << cure1->getType() << std::endl;
	else std::cout << "NULL" << std::endl;

	std::cout << "Copied source creates: ";
	if (cure2) std::cout << cure2->getType() << std::endl;
	else std::cout << "NULL" << std::endl;

	delete cure1;
	delete cure2;
	delete src3;
	delete src2;
	delete david;
	delete charlie;
	delete bob;
	delete alice;
	delete src;

	return 0;
}
