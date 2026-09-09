#include "ScavTrap.hpp"

int main()
{
	std::cout << "=== Testing construction chaining ===" << std::endl;
	ClapTrap basic("R2D2");
	ScavTrap advanced("C3PO");

	std::cout << "\n=== Testing ClapTrap abilities ===" << std::endl;
	basic.attack("Stormtrooper");
	basic.takeDamage(3);
	basic.beRepaired(2);

	std::cout << "\n=== Testing ScavTrap abilities ===" << std::endl;
	advanced.attack("Battle Droid");
	advanced.takeDamage(15);
	advanced.beRepaired(10);
	advanced.guardGate();

	std::cout << "\n=== Testing ScavTrap enhanced stats ===" << std::endl;
	// ScavTrap has more energy (50 vs 10), let's test it
	for (int i = 0; i < 50; i++) {
		advanced.attack("Imperial Forces");
	}

	std::cout << "\n=== Testing damage resistance ===" << std::endl;
	// ScavTrap has more hit points (100 vs 10)
	advanced.takeDamage(90);  // Should still be alive
	advanced.attack("Death Star");
	advanced.guardGate();

	std::cout << "\n=== Testing destruction chaining ===" << std::endl;
	// Destructors will be called automatically in reverse order
	// (advanced first, then basic)

	return 0;
}
