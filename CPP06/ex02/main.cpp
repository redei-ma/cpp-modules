#include "function.hpp"

int main(void)
{
	std::srand(std::time(0));

	std::cout << "=== Random test ===" << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << "\n--- Test " << (i+1) << " ---" << std::endl;

		Base* obj = generate();

		std::cout << "With pointer: ";
		identify(obj);

		std::cout << "With reference: ";
		identify(*obj);

		delete obj;
	}

	std::cout << "\n=== Manual test ===" << std::endl;

	Base* objA = new A();
	Base* objB = new B();
	Base* objC = new C();

	std::cout << "\nObject A:" << std::endl;
	identify(objA);
	identify(*objA);

	std::cout << "\nObject B:" << std::endl;
	identify(objB);
	identify(*objB);

	std::cout << "\nObject C:" << std::endl;
	identify(objC);
	identify(*objC);

	delete objA;
	delete objB;
	delete objC;

	return 0;
}
