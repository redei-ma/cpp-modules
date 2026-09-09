#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include <stdexcept>

class	Intern
{
	private:
		static const std::string	forms[3];

	public:
		Intern();
		Intern(const Intern& other);
		Intern&	operator=(const Intern& other);
		~Intern();

		AForm*	makeForm(const std::string& formName, const std::string& target)	const;

		class	FormNotFound : public std::exception
		{
			public:
				virtual ~FormNotFound()	throw();
				virtual const char* what()	const throw();
		};
};

#endif
