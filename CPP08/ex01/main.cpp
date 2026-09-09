#include "Span.hpp"
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <list>

int main()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << std::string(60, '=') << std::endl;

	Span sp2 = Span(10000);
	try {
		std::srand(std::time(0));
		for (int i = 0; i < 10000; i++)
			sp2.addNumber(std::rand());
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::string(60, '=') << std::endl;

	Span	sp3 = Span(2000);
	int		arr[] = {-10, 1, 0};
	try {
		sp3.addRange(arr, arr + 3);
		std::cout << sp3.shortestSpan() << std::endl;
		std::cout << sp3.longestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::string(60, '=') << std::endl;

	Span	sp4 = Span(2000);
	int		arr2[1] = {42};
	try {
		sp4.addRange(arr2, arr2 + 1);
		std::cout << sp4.shortestSpan() << std::endl;
		std::cout << sp4.longestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::string(60, '=') << std::endl;

	Span	sp5 = Span(2000);
	std::list<int> lst;
	lst.push_back(232);
	lst.push_back(3);
	lst.push_back(543);
	lst.push_back(432);
	lst.push_back(34);
	lst.push_back(-45);
	lst.push_back(-4);
	try {
		sp5.addRange(lst.begin(), lst.end());
		std::cout << sp5.shortestSpan() << std::endl;
		std::cout << sp5.longestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return (0);
}
