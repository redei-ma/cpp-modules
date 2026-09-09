#include "Zombie.hpp"

int	main(void)
{
	std::cout << "STACK ALLOCATION" << std::endl;
	Zombie Sammy("Sammy");
	Sammy.announce();

	std::cout << "---------------------------" << std::endl
				<< "HEAP ALLOCATION" <<std::endl;
	randomChump("Jonny");

	std::cout << "---------------------------" << std::endl
				<< "END PROGRAM" << std::endl;

	return (0);
}
