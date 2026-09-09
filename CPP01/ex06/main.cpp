#include "Harl.hpp"

static int findCase(const std::string &level)
{
	if (level == "DEBUG" || level == "debug")
		return (0);
	else if (level == "INFO" || level == "info")
		return (1);
	else if (level == "WARNING" || level == "warning")
		return (2);
	else if (level == "ERROR" || level == "error")
		return (3);
	return (-1);
}

int main(int ac, char **av)
{
	Harl harl;

	if (ac != 2) {
		std::cerr << "Bad number of arguments" << std::endl;
		return (1);
	}
	switch (findCase(av[1])) {
		case 0:
			harl.complain(0);
			// fall through
		case 1:
			harl.complain(1);
			// fall through
		case 2:
			harl.complain(2);
			// fall through
		case 3:
			harl.complain(3);
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return (0);
}
