#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class	Cure : public AMateria
{
	private:
		Cure&	operator=(const Cure& other);

	public:
		Cure();
		Cure(const Cure& other);
		~Cure();

		virtual Cure* clone() const;
		virtual	void use(ICharacter& target);
};

#endif
