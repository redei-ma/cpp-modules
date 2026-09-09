#include "ClapTrap.hpp"

int main()
{
	std::cout << "=== Creating ClapTraps ===" << std::endl;
	ClapTrap robot1("R2D2");
	ClapTrap robot2("C3PO");

	std::cout << "\n=== Basic attacks ===" << std::endl;
	robot1.attack("Stormtrooper");
	robot2.attack("Battle Droid");

	std::cout << "\n=== Taking damage ===" << std::endl;
	robot1.takeDamage(3);
	robot2.takeDamage(7);

	std::cout << "\n=== Repairing ===" << std::endl;
	robot1.beRepaired(2);
	robot2.beRepaired(5);

	std::cout << "\n=== Testing energy depletion ===" << std::endl;
	// robot1 has already spent 2 of its 10 energy points, one attacking and one repairing
	for (int i = 0; i < 8; i++) {
		robot1.attack("Enemy");
	}
	// this one must fail, the energy is gone
	robot1.attack("Another Enemy");

	std::cout << "\n=== Testing zero hit points ===" << std::endl;
	robot2.takeDamage(20); // brings it down to 0 hit points
	std::cout << "Trying to attack when dead:" << std::endl;
	robot2.attack("Enemy");
	std::cout << "Trying to repair when dead:" << std::endl;
	robot2.beRepaired(5);

	std::cout << "\n=== End of program ===" << std::endl;
	return 0;
}
