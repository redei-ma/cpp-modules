#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					value;
		static const int	fraction;

	public:
		Fixed();
		Fixed(int const number);
		Fixed(float const number);
		Fixed(const Fixed& other);
		Fixed&				operator=(const Fixed& other);
		Fixed				operator+(const Fixed& other) const;
		Fixed				operator-(const Fixed& other) const;
		Fixed				operator*(const Fixed& other) const;
		Fixed				operator/(const Fixed& other) const;
		bool				operator>(const Fixed& other) const;
		bool				operator<(const Fixed& other) const;
		bool				operator>=(const Fixed& other) const;
		bool				operator<=(const Fixed& other) const;
		bool				operator==(const Fixed& other) const;
		bool				operator!=(const Fixed& other) const;
		Fixed&				operator++();
		Fixed				operator++(int);
		Fixed&				operator--();
		Fixed				operator--(int);
		static Fixed&		min(Fixed& one, Fixed& two);
		static const Fixed&	min(const Fixed& one, const Fixed& two);
		static Fixed&		max(Fixed& one, Fixed& two);
		static const Fixed&	max(const Fixed& one, const Fixed& two);
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;
		~Fixed();
};

std::ostream&	operator<<(std::ostream& stream, const Fixed& fixed);

#endif
