#include "BitcoinExchange.hpp"
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <iomanip>

int main(int ac, char **av)
{
	if (ac != 2) {
		std::cerr << "Error: usage: ./btc <input file>" << std::endl;
		return 1;
	}

	std::ifstream input(av[1]);
	std::string str;

	if (!input) {
		std::cerr << "Error: Can't open " << av[1] << std::endl;
		return 1;
	}

	std::cout << std::fixed << std::setprecision(2);
	try {
		BitcoinExchange exch;
		std::string date;
		double quantity;
		double price;

		// First line dropped as header: a file without one loses its first entry.
		if (!std::getline(input, str))
			throw std::logic_error("Empty input");
		while (std::getline(input, str)) {
			try {
				if (str.empty())
					continue;
				exch.parseLine(str, date, quantity);
				price = exch.findPrice(date);
				std::cout << date << " => " << quantity << " = " << quantity * price << std::endl;
			}
			catch (std::exception &e) {
				std::cerr << "Error: " << e.what() << std::endl;
			}
		}
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}
