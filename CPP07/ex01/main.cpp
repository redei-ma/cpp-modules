#include "iter.hpp"
#include <string>

template <typename T>
void	print(T const &x)
{
	std::cout << x << std::endl;
}

template <typename T>
void	square(T &x)
{
	x = x * x;
	std::cout << x << std::endl;
}

void	plusHello(std::string &str)
{
	str = "Hello " + str;
	std::cout << str << std::endl;
}

int	main()
{
	const int arr[3] = {1, 2, 3};
	iter(arr, 3, print<int>);
	std::cout << std::endl;

	int arr2[3] = {1, 2, 3};
	iter(arr2, 3, square<int>);
	std::cout << std::endl;

	std::string ptr[3] = {"World", "Guys", "Girls"};
	iter(ptr, 3, print<std::string>);
	std::cout << std::endl;
	iter(ptr, 3, plusHello);
	return 0;
}
