/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:19:17 by lkoc              #+#    #+#             */
/*   Updated: 2025/01/06 15:18:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
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
	std::cout << "Int constructor called" << std::endl;
	this->value = value << Fixed::bits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(value * (1 << Fixed::bits));
}


Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = other.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}

int	Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}