#include "function.hpp"

Base*	generate(void)
{
	const int	r = std::rand() % 3;

	switch (r) {
		case (0):
			return (new A());
		case (1):
			return (new B());
		case (2):
			return (new C());
		default:
			return (new A());
	}
}

void	identify(Base* p)
{
	A *isA = dynamic_cast<A*>(p);
	B *isB = dynamic_cast<B*>(p);
	C *isC = dynamic_cast<C*>(p);

	std::cout << "Type object: ";
	if (isA)
		std::cout << "A";
	else if (isB)
		std::cout << "B";
	else if (isC)
		std::cout << "C";
	else
		std::cout << "Error: object type not found";
	std::cout << std::endl;
}

void	identify(Base& p)
{
	try {
		A &isA = dynamic_cast<A&>(p);
		static_cast<void>(isA);
		std::cout << "Type object: A" << std::endl;
	}
	catch (...) {
		try {
			B &isB = dynamic_cast<B&>(p);
			static_cast<void>(isB);
			std::cout << "Type object: B" << std::endl;
		}
		catch (...) {
			try {
				C &isC = dynamic_cast<C&>(p);
				static_cast<void>(isC);
				std::cout << "Type object: C" << std::endl;
			}
			catch (...) {
				std::cout << "Error: object type not found" << std::endl;
			}
		}
	}
}
