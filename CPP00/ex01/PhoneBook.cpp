#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::AddContact(const int index)
{
	this->contact[index].SetFirstName();
	this->contact[index].SetLastName();
	this->contact[index].SetNickname();
	this->contact[index].SetNumber();
	this->contact[index].SetSecret();
	std::cout << std::endl;
	std::cout << "Contact added at index " << index << std::endl;
	std::cout << std::endl;
}

void PhoneBook::PrintOneContact(const int index) const
{
	std::cout << this->contact[index].GetFirstName() << std::endl;
	std::cout << this->contact[index].GetLastName() << std::endl;
	std::cout << this->contact[index].GetNickname() << std::endl;
	std::cout << this->contact[index].GetNumber() << std::endl;
	std::cout << this->contact[index].GetSecret() << std::endl;
}

bool PhoneBook::IsValidIndex(std::string search, int &index) const
{
	if (search.empty())
		return (false);
	for (std::size_t i = 0; i < search.length(); i++) {
		if (!std::isdigit((unsigned char)search[i]))
			return (false);
	}
	index = std::atoi(search.c_str());
	if (index < 0 || index > 7)
		return (false);
	if (this->contact[index].GetFirstName().empty())
		return (false);
	return (true);
}

static std::string resizing(std::string str)
{
	int len = str.length();

	if (len > 10) {
		str = str.substr(0, 10);
		str[9] = '.';
	}
	else
		str = std::string(10 - len, ' ') + str;
	return (str);
}

void PhoneBook::PrintAllContact() const
{
	std::cout << "|----------------------------------|" << std::endl;
	std::cout << "|I|First Name|Last Name |Nickname  |" << std::endl;
	std::cout << "|----------------------------------|" << std::endl;
	for (int index = 0; index < 8; index++) {
		if (this->contact[index].GetFirstName().empty())
			return;
		std::cout << "|" << index << "|";
		std::cout << resizing(this->contact[index].GetFirstName()) << "|";
		std::cout << resizing(this->contact[index].GetLastName()) << "|";
		std::cout << resizing(this->contact[index].GetNickname()) << "|";
		std::cout << std::endl;
	}
}

void PhoneBook::SearchContact()
{
	std::string search;

	if (this->contact[0].GetFirstName().empty()) {
		std::cout << "PhoneBook is empty." << std::endl;
		std::cout << std::endl;
		return;
	}
	PrintAllContact();
	std::cout << std::endl;
	std::cout << "What index you want to see?" << std::endl;
	if (!std::getline(std::cin, search))
		std::exit(1);
	std::cout << std::endl;

	int index;
	if (!IsValidIndex(search, index))
		std::cout << "You should see an eye doctor." << std::endl;
	else
		PrintOneContact(index);
	std::cout << std::endl;
}
