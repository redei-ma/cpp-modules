#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>

class	Bureaucrat;

class	Form
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			gradeToSign;
		const int			gradeToExec;

	public:
		Form();
		Form(const std::string& name, int gradeToSign, int gradeToExec);
		Form(const Form& other);
		Form&	operator=(const Form& other);
		~Form();
		std::string	getName()	const;
		bool		getIsSigned()	const;
		int			getGradeToSign()	const;
		int			getGradeToExec()	const;
		void		beSigned(const Bureaucrat& bureaucrat);
		class	GradeTooHighException : public std::exception
		{
			public:
				virtual ~GradeTooHighException()	throw();
				virtual const char* what()	const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				virtual ~GradeTooLowException()	throw();
				virtual const char* what()	const throw();
		};
};

std::ostream& operator<<(std::ostream& stream, const Form& me);

#endif
