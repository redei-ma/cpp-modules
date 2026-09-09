#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	std::cout << "=== Testing construction chaining ===" << std::endl;
	ClapTrap basic("R2D2");
	ScavTrap guardian("C3PO");
	FragTrap warrior("BB8");

	std::cout << "\n=== Testing ClapTrap abilities ===" << std::endl;
	basic.attack("Stormtrooper");
	basic.takeDamage(3);
	basic.beRepaired(2);

	std::cout << "\n=== Testing ScavTrap abilities ===" << std::endl;
	guardian.attack("Battle Droid");
	guardian.takeDamage(15);
	guardian.beRepaired(10);
	guardian.guardGate();

	std::cout << "\n=== Testing FragTrap abilities ===" << std::endl;
	warrior.attack("Sith Lord");
	warrior.takeDamage(25);
	warrior.beRepaired(15);
	warrior.highFivesGuys();

	std::cout << "\n=== Testing FragTrap enhanced stats ===" << std::endl;
	// FragTrap has 100 energy vs ScavTrap's 50
	std::cout << "FragTrap energy test (100 energy points):" << std::endl;
	for (int i = 0; i < 15; i++) {
		warrior.attack("Imperial Army");
	}

	std::cout << "\n=== Testing FragTrap damage power ===" << std::endl;
	// FragTrap does 30 damage vs ScavTrap's 20
	std::cout << "FragTrap damage test (30 attack damage):" << std::endl;
	warrior.attack("Darth Vader");

	std::cout << "\n=== Testing special abilities ===" << std::endl;
	guardian.guardGate();
	warrior.highFivesGuys();

	std::cout << "\n=== Testing destruction chaining ===" << std::endl;
	// Destructors will be called in reverse order:
	// warrior (FragTrap) -> guardian (ScavTrap) -> basic (ClapTrap)

	return 0;
}
