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
