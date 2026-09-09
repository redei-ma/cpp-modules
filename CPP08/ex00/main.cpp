#include "easyfind.hpp"
#include <vector>
#include <iostream>

int	main()
{
	int arr[4] = {2, 5, 63, -1};
	std::vector<int> vec(arr, arr + 4);

	try {
		std::vector<int>::const_iterator found = easyfind(vec, 63);
		std::cout << "Value found at index: " << found - vec.begin() << std::endl;
	}
	catch (const std::runtime_error& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		std::vector<int>::const_iterator found = easyfind(vec, 9);
		std::cout << "Value found at index: " << found - vec.begin() << std::endl;
	}
	catch (const std::runtime_error& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	vec.push_back(3);
	vec.push_back(23);

	try {
		std::vector<int>::const_iterator found = easyfind(vec, 23);
		std::cout << "Value found at index: " << found - vec.begin() << std::endl;
	}
	catch (const std::runtime_error& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}
