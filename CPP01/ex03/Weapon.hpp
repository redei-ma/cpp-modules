#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class	Weapon
{
	private:
		std::string	type;
		Weapon();

	public:
		Weapon(const std::string weaponType);
		const std::string&	getType() const;
		void				setType(const std::string weaponType);
		~Weapon();
};

#endif
