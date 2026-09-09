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
