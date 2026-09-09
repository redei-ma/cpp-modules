#!/bin/bash
# Recreates the ex01 PhoneBook in a fresh directory, sources and Makefile.
# The heredocs are quoted, so tabs and backslashes are written verbatim.
#
# Usage: ./setup_phonebook.sh [target directory]   (default: phonebook)

set -e

DIR="${1:-phonebook}"
mkdir -p "$DIR"
cd "$DIR"

cat > Contact.hpp << 'PHONEBOOK_EOF'
#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <cctype>

class	Contact
{
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	number;
		std::string	secret;
	public:
		Contact();

		std::string	GetString(const char *msg);
		void		SetFirstName();
		void		SetLastName();
		void		SetNickname();
		void		SetNumber();
		void		SetSecret();
		std::string	GetFirstName() const;
		std::string	GetLastName() const;
		std::string	GetNickname() const;
		std::string	GetNumber() const;
		std::string	GetSecret() const;

		~Contact();
};

#endif
PHONEBOOK_EOF

cat > Contact.cpp << 'PHONEBOOK_EOF'
#include "Contact.hpp"

Contact::Contact()
{}

Contact::~Contact()
{}

static bool	ft_is_white_string(const std::string& str)
{
	for (std::size_t i = 0; i < str.length(); i++) {
		if (!std::isspace((unsigned char)str[i]))
			return (false);
	}
	return (true);
}

std::string Contact::GetString(const char *msg)
{
	std::string string;

	do {
		std::cout << msg << std::endl;
		if (!std::getline(std::cin, string))
			std::exit(1);
		if (string.empty() || ft_is_white_string(string))
			std::cout << "You can't let empty fields:" << std::endl;
	}	while (string.empty() || ft_is_white_string(string));
	return (string);
}

void	Contact::SetFirstName()
{
	this->firstName = GetString("Insert your first name:");
}

void	Contact::SetLastName()
{
	this->lastName = GetString("Insert your last name:");
}

void	Contact::SetNickname()
{
	this->nickname = GetString("Insert your nickname:");
}

void	Contact::SetNumber()
{
	this->number = GetString("Insert your phone number:");
}

void	Contact::SetSecret()
{
	this->secret = GetString("Tell me your darkest desire:");
}

std::string	Contact::GetFirstName() const
{
	return (this->firstName);
}

std::string	Contact::GetLastName() const
{
	return (this->lastName);
}

std::string	Contact::GetNickname() const
{
	return (this->nickname);
}

std::string	Contact::GetNumber() const
{
	return (this->number);
}

std::string	Contact::GetSecret() const
{
	return (this->secret);
}
PHONEBOOK_EOF

cat > PhoneBook.hpp << 'PHONEBOOK_EOF'
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class	PhoneBook
{
	private:
		Contact	contact[8];
	public:
		PhoneBook();

		void	AddContact(int index); 
		void	SearchContact();
		void	PrintAllContact() const;
		void	PrintOneContact(int search) const;
		bool	IsValidIndex(std::string search, int& index) const;

		~PhoneBook();
};

#endif
PHONEBOOK_EOF

cat > PhoneBook.cpp << 'PHONEBOOK_EOF'
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
PHONEBOOK_EOF

cat > main.cpp << 'PHONEBOOK_EOF'
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
PHONEBOOK_EOF

cat > Makefile << 'PHONEBOOK_EOF'
NAME = phoneBook
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =	main.cpp \
		Contact.cpp \
		PhoneBook.cpp

all: $(NAME)

$(NAME): $(SRCS)
	@echo "Compiling executable..."
	@$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

clean:
	@echo "Nothing to clean..."

fclean: clean
	@echo "Removing executable..."
	@rm -rf $(NAME)

re: fclean all

debug: fclean
	@$(CXX) $(CXXFLAGS) -g $(SRCS) -o $(NAME)

.PHONY: all clean fclean re debug
.SILENT:
PHONEBOOK_EOF

echo "PhoneBook written to $DIR:"
for f in Contact.hpp Contact.cpp PhoneBook.hpp PhoneBook.cpp main.cpp Makefile; do echo "  $f"; done
echo
echo "Build and run:"
echo "  cd $DIR && make && ./phoneBook"
