#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class	Character : public ICharacter
{
	private:
		std::string	name;
		AMateria	*slots[4];
		AMateria	*unequipped[50];
		Character();

	public:
		Character(const std::string& name);
		Character(const Character& other);
		Character&	operator=(const Character& other);
		virtual ~Character();
		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
};

#endif
