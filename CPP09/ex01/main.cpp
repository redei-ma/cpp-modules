#include "RPN.hpp"
#include <iostream>
#include <iomanip>

int	main(int ac, char **av)
{
	if (ac != 2) {
		std::cerr << "Error: Invalid input" << std::endl;
		return 1;
	}

	std::cout << std::fixed << std::setprecision(2);

	try {
		RPN ReversePolishNotation;
		double	res = ReversePolishNotation.calculateRPN(av[1]);
		std::cout << res << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
