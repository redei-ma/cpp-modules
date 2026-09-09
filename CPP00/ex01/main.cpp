#include "PhoneBook.hpp"

static void	printHeader()
{
	std::cout << "Type ADD to create a new contact." << std::endl;
	std::cout << "Type SEARCH to find a contact in phonebook." << std::endl;
	std::cout << "Type EXIT to close the phonebook." << std::endl;
	std::cout << std::endl;
	std::cout << "Please, insert your command: " << std::endl;
}

int	main()
{
	PhoneBook 	myPhoneBook;
	std::string	line;
	int			index = 0;

	std::cout << std::endl;
	do {
		printHeader();
		if (!std::getline(std::cin, line))
			return (1);
		std::cout << std::endl;
		if (!line.compare("ADD")) {
			myPhoneBook.AddContact(index);
			if (index == 7)
				index = 0;
			else
				index++;
		}
		else if (!line.compare("SEARCH"))
			myPhoneBook.SearchContact();
	}	while (line.compare("EXIT"));

	std::cout << "Goodbye" << std::endl;
	return (0);
}
