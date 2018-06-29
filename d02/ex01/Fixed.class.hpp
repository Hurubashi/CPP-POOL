
#ifndef FIXED_CLASS_HPP
#define FIXED_CLASS_HPP

#include <iostream>
#include <cmath>

class Fixed {

public:
	Fixed(void);
	~Fixed(void);
	Fixed(const Fixed & other);
	Fixed& operator=(const Fixed &rhs);
	Fixed(const int value);
	Fixed(float value);

	float toFloat( void ) const;
	int toInt( void ) const;
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

private:
	int					_rawBits;
	static const int	_FractBits;

};

std::ostream	& operator << (std::ostream & out, Fixed const & fixed);

#endif