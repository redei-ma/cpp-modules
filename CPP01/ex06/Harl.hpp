#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class	Harl
{
	private:
		typedef void (Harl::*HarlFunction)(void);
		HarlFunction	functions[4];

		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

	public:
		Harl();
		void	complain(int i);
		~Harl();
};

#endif
