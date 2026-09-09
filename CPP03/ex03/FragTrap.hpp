#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap	// virtual: a DiamondTrap must hold one ClapTrap, not two
{
	public:
		FragTrap();
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& other);
		FragTrap&		operator=(const FragTrap& other);
		void			attack(const std::string& target);
		void			highFivesGuys(void);
		~FragTrap();
};

#endif
