/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoc <lkoc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:19:17 by lkoc              #+#    #+#             */
/*   Updated: 2025/01/08 17:30:05 by lkoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->value = 0;
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

int Fixed::toInt(void) const
{
	return (this->value >> Fixed::bits); // dzielenie na 2^8
}

float Fixed::toFloat(void) const
{
	return ((float)this->value / (1 << Fixed::bits)); // dzielenie na (1 * 2^8) // z (float) cpp nie ucina po przecinku
}

Fixed::Fixed(const int value)
{
	//std::cout << "Int constructor called" << std::endl;
	this->value = value << Fixed::bits;
}

Fixed::Fixed(const float value)
{
	//std::cout << "Float constructor called" << std::endl;
	this->value = roundf(value * (1 << Fixed::bits));
}


Fixed::Fixed(const Fixed &other)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(other.getRawBits());
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}

int	Fixed::getRawBits(void) const  // returns the raw value of the fixed point value
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits(int const raw) // sets the class value
{ 
	this->value = raw;
}

/////ex02

//comparison

bool Fixed::operator > (const Fixed &other) const
{
	return (this->value > other.value);	
}

bool Fixed::operator < (const Fixed &other) const
{
	return (this->value < other.value);
}

bool Fixed::operator >= (const Fixed &other) const
{
	return (this->value >= other.value);
}

bool Fixed::operator <= (const Fixed &other) const
{
	return (this->value <= other.value);
}

bool Fixed::operator == (const Fixed &other) const
{
	return (this->value == other.value);
}

bool Fixed::operator != (const Fixed &other) const
{
	return (this->value != other.value);
}

// Arithmetic

Fixed Fixed::operator + (const Fixed &other) const
{
	Fixed result;

	result.setRawBits(this->getRawBits() + other.getRawBits());
	return (result);
}

Fixed Fixed::operator - (const Fixed &other) const
{
	Fixed result;

	result.setRawBits(this->getRawBits() - other.getRawBits());
	return (result);
}

Fixed Fixed::operator * (const Fixed &other) const
{
	Fixed result;

	result.setRawBits((this->getRawBits() * other.getRawBits()) >> Fixed::bits);
	return (result);
}

Fixed Fixed::operator / (const Fixed &other) const
{
	Fixed result;

	result.setRawBits((this->getRawBits() << Fixed::bits) / other.getRawBits());
	return (result);
}

// increment decrement

Fixed&	Fixed::operator ++() //pre
{
	this->value++;
	return (*this);
}

Fixed	Fixed::operator ++(int) //post
{
	Fixed	temp(*this);

	this->value++;
	return (temp);
}

Fixed&	Fixed::operator --()
{
	this->value--;
	return (*this);
}

Fixed	Fixed::operator --(int)
{
	Fixed	temp(*this);

	this->value--;
	return (temp);
}

// max min

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}
