#include "Fixed.hpp"

const int Fixed::fraction = 8;

Fixed::Fixed() :value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const number) :value(number * (1 << fraction))
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const number) :value(roundf(number * (1 << fraction)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) :value(other.value)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->value = other.value;
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	value = raw;
}

float	Fixed::toFloat(void) const
{
	float floatNumber = (float)value/(1 << fraction);
	return (floatNumber);
}

int	Fixed::toInt(void) const
{
	int intNumber = value / (1 << fraction);
	return (intNumber);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

std::ostream&	operator<<(std::ostream& stream, const Fixed& fixed)
{
	stream << fixed.toFloat();
	return (stream);
}
