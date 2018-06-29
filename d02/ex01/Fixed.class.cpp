#include "Fixed.class.hpp"

const int 	Fixed::_FractBits = 8;

Fixed::Fixed(void) {
	this->_rawBits = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator= (const Fixed &rhs) {
	std::cout << "Assignation operator called" << std::endl;
	this->_rawBits = rhs.getRawBits();
	return *this;
}

Fixed::Fixed(int value) {
	std::cout << "Int constructor called" << std::endl;
	value = value << Fixed::_FractBits;
	this->_rawBits = value;
}

Fixed::Fixed(float value) {
	std::cout << "Float constructor called" << std::endl;
	value = roundf(value * (1 << Fixed::_FractBits));
	this->_rawBits = (int)value;
}

void			Fixed::setRawBits(int const raw) {
	this->_rawBits = raw;
}

int				Fixed::getRawBits(void) const {
	return (this->_rawBits);
}

float			Fixed::toFloat() const {
	return ((float)this->_rawBits / (1 << Fixed::_FractBits));
}

int				Fixed::toInt() const {
	return (this->_rawBits >> Fixed::_FractBits);
}

std::ostream	& operator << (std::ostream & out, Fixed const & fixed)
{
	out << fixed.toFloat();
	return (out);
}