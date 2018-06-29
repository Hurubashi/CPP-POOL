#include "Fixed.class.hpp"
#include "iostream"

const int 	Fixed::_FractBits = 8;

/*
 * Constructors
 */

Fixed::Fixed(void) {
	this->_rawBits = 0;
//	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void) {
//	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
//	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(int value) {
//	std::cout << "Int constructor called" << std::endl;
	value = value << Fixed::_FractBits;
	this->_rawBits = value;
}

Fixed::Fixed(float value) {
//	std::cout << "Float constructor called" << std::endl;
	value = roundf(value * (1 << Fixed::_FractBits));
	this->_rawBits = (int)value;
}

/*
 * Funcs old
 */

Fixed& Fixed::operator= (const Fixed &rhs) {
//	std::cout << "Assignation operator called" << std::endl;
	this->_rawBits = rhs.getRawBits();
	return *this;
}

void		Fixed::setRawBits(int const raw) {
	this->_rawBits = raw;
}

int			Fixed::getRawBits(void) const {
	return (this->_rawBits);
}

float		Fixed::toFloat() const {
	return ((float)this->_rawBits / (1 << Fixed::_FractBits));
}

int			Fixed::toInt() const {
	return (this->_rawBits >> Fixed::_FractBits);
}

std::ostream	& operator << (std::ostream & out, Fixed const & fixed)
{
	out << fixed.toFloat();
	return (out);
}

/*
 * Six comparison operators : >, <, >=, <=, == and !=.
 */

bool		Fixed::operator > (Fixed const & obj) const {
	if (this->getRawBits() > obj.getRawBits())
		return (true);
	return (false);
}

bool		Fixed::operator < (Fixed const & obj) const {
	if (this->getRawBits() < obj.getRawBits())
		return (true);
	return (false);
}

bool		Fixed::operator >= (Fixed const & obj) const {
	if (this->getRawBits() >= obj.getRawBits())
		return (true);
	return (false);
}

bool		Fixed::operator <= (Fixed const & obj) const {
	if (this->getRawBits() <= obj.getRawBits())
		return (true);
	return (false);
}

bool		Fixed::operator == (Fixed const & obj) const {
	if (this->getRawBits() == obj.getRawBits())
		return (true);
	return (false);
}

bool		Fixed::operator != (Fixed const & obj) const {
	if (this->getRawBits() != obj.getRawBits())
		return (true);
	return (false);
}

/*
 * Four arithmetic operators : +, -, *, and /.
 */

Fixed		Fixed::operator + (const Fixed &rhs) {
	this->_rawBits = (this->getRawBits() + rhs.getRawBits()) >> 8;
	return (*this);
}

Fixed		Fixed::operator - (const Fixed &rhs) {
	this->_rawBits = (this->getRawBits() - rhs.getRawBits()) >> 8;
	return (*this);
}

Fixed		Fixed::operator * (const Fixed &rhs) {
	this->_rawBits = (this->getRawBits() * rhs.getRawBits()) >> 8;
	return (*this);
}

Fixed		Fixed::operator / (const Fixed &rhs) {
	this->_rawBits = (this->getRawBits() / rhs.getRawBits()) >> 8;
	return (*this);
}

/*
 * The pre-increment, post-increment, pre-decrement and post-decrement operators
 */

Fixed		&Fixed::operator++() {
	this->_rawBits++;
	return (*this);
}

Fixed		Fixed::operator++(int) {
	Fixed	ret(*this);

	++*this;
	return ret;
}

Fixed		&Fixed::operator--() {
	this->_rawBits--;
	return (*this);
}

Fixed		Fixed::operator--(int) {
	Fixed	ret(*this);

	--*this;
	return ret;
}

/*
 * The pre-increment, post-increment, pre-decrement and post-decrement operators
 */

Fixed			&Fixed::max( Fixed &obj1, Fixed &obj2) {
	if (obj1.getRawBits() > obj2.getRawBits())
		return (obj1);
	return (obj2);
}

Fixed	const	&Fixed::max(const Fixed &obj1, const Fixed &obj2) {
	if (obj1.getRawBits() > obj2.getRawBits())
		return (obj1);
	return (obj2);
}

Fixed			&Fixed::min( Fixed &obj1, Fixed &obj2) {
	if (obj1.getRawBits() < obj2.getRawBits())
		return (obj1);
	return (obj2);
}

Fixed	const	&Fixed::min(const Fixed &obj1, const Fixed &obj2) {
	if (obj1.getRawBits() < obj2.getRawBits())
		return (obj1);
	return (obj2);
}
