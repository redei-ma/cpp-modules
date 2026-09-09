#include <iostream>
#include <string>
#include <cctype>

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else {
		for (int i = 1; i < ac; i++) {
			std::string str = av[i];
			for (std::size_t j = 0; j < str.length(); j++) {
				// toupper is undefined for negative values, and char is signed here.
				char c = std::toupper((unsigned char)str[j]);
				std::cout << c;
			}
		}
	}
	std::cout << std::endl;
	return (0);
}
