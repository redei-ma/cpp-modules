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
