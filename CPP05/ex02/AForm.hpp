#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>

class	Bureaucrat;

class	AForm
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			gradeToSign;
		const int			gradeToExec;

	public:
		AForm();
		AForm(const std::string& name, int gradeToSign, int gradeToExec);
		AForm(const AForm& other);
		AForm&	operator=(const AForm& other);
		virtual ~AForm();
		std::string		getName()	const;
		bool			getIsSigned()	const;
		int				getGradeToSign()	const;
		int				getGradeToExec()	const;
		void			beSigned(const Bureaucrat& bureaucrat);
		void			execute(Bureaucrat const & executor)	const;
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
		class	FormNotSigned : public std::exception
		{
			public:
				virtual ~FormNotSigned()	throw();
				virtual const char* what()	const throw();
		};

	protected:
		// execute() checks signature and grade, then calls this: a concrete form cannot skip the checks
		virtual void	executeAction()	const = 0;
};

std::ostream& operator<<(std::ostream& stream, const AForm& me);

#endif
