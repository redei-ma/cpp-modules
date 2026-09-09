#include <iostream>
#include <stdexcept>
#include "Array.hpp"

int main()
{
	try {
		Array<int> arr1(3);
		arr1[0] = 10;
		arr1[1] = 20;
		arr1[2] = 30;

		Array<int> arr2 = arr1;
		arr2[0] = 999;

		std::cout << "arr1[0] = " << arr1[0] << std::endl;
		std::cout << "arr2[0] = " << arr2[0] << std::endl;

		std::cout << "Size: " << arr1.size() << std::endl;

		arr1[5];	//std::exceptions

	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
