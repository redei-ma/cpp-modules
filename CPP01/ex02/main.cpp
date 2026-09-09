#include <iostream>
#include <string>

int	main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string* stringPTR = &string;
	std::string& stringREF = string;

	std::cout << "MEMORY ADDRESS" << std::endl
				<< "string: " << &string << std::endl
				<< "stringPTR: " << stringPTR << std::endl
				<< "stringREF: " << &stringREF << std::endl;

	std::cout << "VALUE" << std::endl
				<< "string: " << string << std::endl
				<< "stringPTR: " << *stringPTR << std::endl
				<< "stringREF: " << stringREF << std::endl;
	return (0);
}
