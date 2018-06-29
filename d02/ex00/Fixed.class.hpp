
#ifndef FIXED_CLASS_HPP
#define FIXED_CLASS_HPP

#include <iostream>

class Fixed {

public:
	Fixed(void);
	~Fixed(void);
	Fixed(const Fixed & other);
	Fixed& operator=(const Fixed &rhs);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

private:
	int					_rawBits;
	static const int	_FractBits;

};


#endif