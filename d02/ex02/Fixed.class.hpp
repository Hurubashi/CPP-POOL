
#ifndef FIXED_CLASS_HPP
#define FIXED_CLASS_HPP

#include <iostream>
#include <cmath>

class Fixed {

public:
	Fixed(void);
	~Fixed(void);
	Fixed(const Fixed & other);
	Fixed &operator = (const Fixed &rhs);
	Fixed(const int value);
	Fixed(float value);

	float	toFloat( void ) const;
	int		toInt( void ) const;
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	bool	operator > (const Fixed &rhs) const ;
	bool	operator < (const Fixed &rhs) const ;
	bool	operator >= (const Fixed &rhs) const ;
	bool	operator <= (const Fixed &rhs) const ;
	bool	operator == (const Fixed &rhs) const ;
	bool	operator != (const Fixed &rhs) const ;

	Fixed	operator + (const Fixed &rhs);
	Fixed	operator - (const Fixed &rhs);
	Fixed	operator * (const Fixed &rhs);
	Fixed	operator / (const Fixed &rhs);

	Fixed	&operator++ (void);
	Fixed	operator++ (int);
	Fixed	&operator-- (void);
	Fixed	operator-- (int);

	static Fixed const	&max(const Fixed &obj1, const Fixed &obj2);
	static Fixed const	&min(const Fixed &obj1, const Fixed &obj2);
	static Fixed		&max(Fixed &obj1, Fixed &obj2);
	static Fixed		&min(Fixed &obj1, Fixed &obj2);

private:
	int					_rawBits;
	static const int	_FractBits;

};

std::ostream	& operator << (std::ostream & out, Fixed const & fixed);

#endif