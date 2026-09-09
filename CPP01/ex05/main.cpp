#include "Harl.hpp"

int	main(void)
{
	Harl Test;

	std::cout << "PASSING DEBUG" << std::endl;
	Test.complain("DEBUG");
	std::cout << std::endl;
	std::cout << "PASSING INFO" << std::endl;
	Test.complain("INFO");
	std::cout << std::endl;
	std::cout << "PASSING WARNING" << std::endl;
	Test.complain("WARNING");
	std::cout << std::endl;
	std::cout << "PASSING ERROR" << std::endl;
	Test.complain("ERROR");
	std::cout << std::endl;
	return (0);
}
