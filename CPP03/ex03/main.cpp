#include "DiamondTrap.hpp"

int main()
{
	std::cout << "=== Base construction and chaining ===" << std::endl;
	ClapTrap basic("R2D2");
	ScavTrap guardian("C3PO");
	FragTrap warrior("BB8");

	std::cout << "\n=== DiamondTrap construction ===" << std::endl;
	DiamondTrap hybrid("DT1");

	std::cout << "\n=== DiamondTrap default constructor ===" << std::endl;
	DiamondTrap defaultDiamond;
	defaultDiamond.whoAmI();

	std::cout << "\n=== whoAmI ===" << std::endl;
	hybrid.whoAmI();

	std::cout << "\n=== DiamondTrap abilities ===" << std::endl;
	hybrid.attack("Enemy");			// should use ScavTrap's attack
	hybrid.takeDamage(20);
	hybrid.beRepaired(10);
	hybrid.guardGate();				// from ScavTrap
	hybrid.highFivesGuys();			// from FragTrap

	std::cout << "\n=== DiamondTrap canonical form ===" << std::endl;
	DiamondTrap hybrid2("DT2");
	DiamondTrap hybrid3(hybrid2);	// copy constructor
	DiamondTrap hybrid4("DT4");
	hybrid4 = hybrid3;				// assignment operator

	hybrid2.whoAmI();
	hybrid3.whoAmI();
	hybrid4.whoAmI();

	std::cout << "\n=== DiamondTrap stats ===" << std::endl;
	std::cout << "DiamondTrap should have:" << std::endl;
	std::cout << "- Hit points from FragTrap (100)" << std::endl;
	std::cout << "- Energy from ScavTrap (50)" << std::endl;
	std::cout << "- Attack damage from FragTrap (30)" << std::endl;

	DiamondTrap statsTest("StatsTester");
	statsTest.attack("Test Target");	// ScavTrap's attack, FragTrap's damage (30)

	std::cout << "\n=== DiamondTrap energy limit ===" << std::endl;
	DiamondTrap energyTest("EnergyTester");
	std::cout << "Energy test (50 points from ScavTrap):" << std::endl;

	// 25 attacks and 30 repairs are 55 actions, five more than the energy allows
	for (int i = 0; i < 25; i++) {
		energyTest.attack("Training Dummy");
	}
	for (int i = 0; i < 30; i++) {
		energyTest.beRepaired(1);
	}
	// these two must fail, the energy is gone
	energyTest.attack("Should fail");
	energyTest.beRepaired(1);

	std::cout << "\n=== DiamondTrap hit points limit ===" << std::endl;
	DiamondTrap hpTest("HPTester");
	std::cout << "Hit points test (100 points from FragTrap):" << std::endl;

	hpTest.takeDamage(90);			// survives with 10 hit points
	hpTest.attack("Survival test");
	hpTest.guardGate();
	hpTest.highFivesGuys();

	hpTest.takeDamage(20);			// dies
	hpTest.attack("Should fail, dead");
	hpTest.beRepaired(10);
	hpTest.guardGate();				// still works, costs neither energy nor hit points
	hpTest.highFivesGuys();

	std::cout << "\n=== Abilities of every class ===" << std::endl;
	std::cout << "ClapTrap:" << std::endl;
	basic.attack("Stormtrooper");	// 0 damage
	basic.takeDamage(3);
	basic.beRepaired(2);

	std::cout << "\nScavTrap:" << std::endl;
	guardian.attack("Battle Droid");	// 20 damage
	guardian.takeDamage(15);
	guardian.beRepaired(10);
	guardian.guardGate();

	std::cout << "\nFragTrap:" << std::endl;
	warrior.attack("Sith Lord");	// 30 damage
	warrior.takeDamage(25);
	warrior.beRepaired(15);
	warrior.highFivesGuys();

	std::cout << "\nDiamondTrap:" << std::endl;
	DiamondTrap finalTest("FinalTest");
	finalTest.attack("Ultimate Enemy");	// ScavTrap's attack, FragTrap's 30 damage
	finalTest.takeDamage(30);
	finalTest.beRepaired(20);
	finalTest.guardGate();			// from ScavTrap
	finalTest.highFivesGuys();		// from FragTrap
	finalTest.whoAmI();				// DiamondTrap's own

	std::cout << "\n=== Destruction chaining ===" << std::endl;
	// each DiamondTrap unwinds as DiamondTrap -> FragTrap -> ScavTrap -> ClapTrap

	return 0;
}
