#include "Zombie.hpp"
#include <cctype>
#include <sstream>

static bool	isValidName(const std::string& search)
{
	if (search.empty())
		return (false);

	for (std::size_t i = 0; i < search.length(); i++) {
		if (!std::isspace((unsigned char)search[i]))
			return (true);
	}
	return (false);
}

static bool	isValidNumber(const std::string& search, int& number)
{
	if (search.empty())
		return (false);
	for (std::size_t i = 0; i < search.length(); i++) {
		if (!std::isdigit((unsigned char)search[i]))
			return (false);
	}

	std::istringstream	ss(search);

	if (!(ss >> number) || !ss.eof())
		return (false);
	if (number <= 0)
		return (false);
	return (true);
}

int	main(void)
{
	Zombie*		horde;
	std::string	search;
	int			number;

	std::cout << "HORDE CREATION" << std::endl;
	std::cout << "How many zombies do you want to create?" << std::endl;
	if (!std::getline(std::cin, search))
		return (1);
	if (!isValidNumber(search, number)) {
		std::cerr << "Not valid number" << std::endl;
		return (1);
	}
	std::cout << "What is your zombie name?" << std::endl;
	if (!std::getline(std::cin, search))
		return (1);
	if (!isValidName(search)) {
		std::cerr << "Not valid name" << std::endl;
		return (1);
	}
	horde = zombieHorde(number, search);
	std::cout << "---------------------------" << std::endl;

	std::cout << "HORDE ANNOUNCEMENT" << std::endl;
	for (int i = 0; i < number; i++)
		horde[i].announce();
	std::cout << "---------------------------" << std::endl;

	delete[] horde;
	return (0);
}
