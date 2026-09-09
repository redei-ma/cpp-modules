#include "Fixed.hpp"

const int Fixed::fraction = 8;

Fixed::Fixed() :value(0)
{}

Fixed::Fixed(int const number) :value(number * (1 << fraction))
{}

Fixed::Fixed(float const number) :value(roundf(number * (1 << fraction)))
{}

Fixed::Fixed(const Fixed& other) :value(other.value)
{}

Fixed::~Fixed()
{}

Fixed&	Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->value = other.value;
	return (*this);
}

Fixed	Fixed::operator+(const Fixed& other) const
{
	Fixed	result;

	result.setRawBits(this->getRawBits() + other.getRawBits());
	return (result);
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	Fixed	result;

	result.setRawBits(this->getRawBits() - other.getRawBits());
	return (result);
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	Fixed	result;

	result.setRawBits((long)this->getRawBits() * other.getRawBits() / (1 << fraction));
	return (result);
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	Fixed	result;

	result.setRawBits((long)this->getRawBits() * (1 << fraction) / other.getRawBits());
	return (result);
}

bool	Fixed::operator>(const Fixed& other) const
{
	return (this->getRawBits() > other.getRawBits());
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (this->getRawBits() < other.getRawBits());
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (this->getRawBits() >= other.getRawBits());
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->getRawBits() <= other.getRawBits());
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (this->getRawBits() == other.getRawBits());
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->getRawBits() != other.getRawBits());
}

Fixed&	Fixed::operator++()
{
	this->value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);

	this->value++;
	return (tmp);
}

Fixed&	Fixed::operator--()
{
	this->value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);

	this->value--;
	return (tmp);
}

Fixed&	Fixed::min(Fixed& one, Fixed& two)
{
	if (one <= two)
		return (one);
	else
		return (two);
}

const Fixed&	Fixed::min(const Fixed& one, const Fixed& two)
{
	if (one <= two)
		return (one);
	else
		return (two);
}

Fixed&	Fixed::max(Fixed& one, Fixed& two)
{
	if (one >= two)
		return (one);
	else
		return (two);
}

const Fixed&	Fixed::max(const Fixed& one, const Fixed& two)
{
	if (one >= two)
		return (one);
	else
		return (two);
}

int	Fixed::getRawBits(void) const
{
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

std::ostream&	operator<<(std::ostream& stream, const Fixed& fixed)
{
	stream << fixed.toFloat();
	return (stream);
}
