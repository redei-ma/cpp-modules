#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <algorithm>
#include <cstdlib>
#include <cerrno>
#include <climits>

template<typename T>
static void print(const T& c, const int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << c[i];
		if (i != size - 1)
		{
			std::cout << " ";
		}
	}
}

static int	*parseNumbers(int ac, char **av)
{
	int sizeNumb = ac - 1;
	int *numbers = new int[sizeNumb];

	for (int i = 1; i < ac; i++)
	{
		char	*endptr;
		errno = 0;
		long	val = strtol(av[i], &endptr, 10);
		if (*endptr != '\0' || errno == ERANGE || val < 0 || val > INT_MAX)
		{
			delete[] numbers;
			std::cerr << "Error: Invalid number" << std::endl;
			return (NULL);
		}
		numbers[i - 1] = (static_cast<int>(val));
	}

	int	*temp = new int[sizeNumb];

	std::copy(numbers, numbers + sizeNumb, temp);
	std::sort(temp, temp + sizeNumb);
	// duplicates are rejected on purpose: the algorithm matches elements by value, not by index
	for (int i = 1; i < sizeNumb; i++)
	{
		if (temp[i] == temp[i - 1])
		{
			delete[] numbers;
			delete[] temp;
			std::cerr << "Error: Duplicate number" << std::endl;
			return (NULL);
		}
	}
	delete[] temp;

	return (numbers);
}

int	main(int ac, char **av)
{
	if (ac < 3)
	{
		std::cerr << "Error: Invalid number of arguments" << std::endl;
		return 1;
	}

	int	*numbers = parseNumbers(ac, av);
	if (!numbers)
	{
		return 1;
	}

	PmergeMe<std::vector<int> >	algoV(numbers, ac - 1);
	PmergeMe<std::deque<int> >	algoD(numbers, ac - 1);

	try
	{
		algoV.execFordJohnson();
		algoD.execFordJohnson();

		std::cout << "Before: ";
		print(numbers, ac - 1);
		std::cout << std::endl;
		std::cout << "After: ";
		print(algoV.getContainer(), ac - 1);
		std::cout << std::endl;
		std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector: " << algoV.getExecTime() << "us" << std::endl;
		std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque: " << algoD.getExecTime() << "us" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	delete[] numbers;
}
