#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _value(0) {std::cout << "Default constructor called" << std::endl;};

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int intValue)
{
	std::cout << "Int constructor called" << std::endl;
	_value = intValue << _fractionalBits;
}

Fixed::Fixed(const float floatValue)
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(floatValue * (1 << _fractionalBits));
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_value = other._value;
	return *this;
}

Fixed &Fixed::operator++()
{
	_value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	_value++;
	return temp;
}

Fixed &Fixed::operator--()
{
	_value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	_value--;
	return temp;
}

bool Fixed::operator>(const Fixed &other) const
{
	return _value > other._value;
}

bool Fixed::operator<(const Fixed &other) const
{
	return _value < other._value;
}

bool Fixed::operator>=(const Fixed &other) const
{
	return _value >= other._value;
}

bool Fixed::operator<=(const Fixed &other) const
{
	return _value <= other._value;
}

bool Fixed::operator==(const Fixed &other) const
{
	return _value == other._value;
}

bool Fixed::operator!=(const Fixed &other) const
{
	return _value != other._value;
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result._value = _value + other._value;
	return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result._value = _value - other._value;
	return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	long long temp = static_cast<long long>(_value) * static_cast<long long>(other._value);
	result._value = static_cast<int>(temp >> _fractionalBits);
	return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;
	long long temp = (static_cast<long long>(_value) << _fractionalBits) / other._value;
	result._value = static_cast<int>(temp);
	return result;
}

Fixed::~Fixed() {std::cout << "Destructor called" << std::endl;};

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(_value) / static_cast<float>(1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
	return _value >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}