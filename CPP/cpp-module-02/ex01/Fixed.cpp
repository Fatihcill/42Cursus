/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:00:00 by fcil              #+#    #+#             */
/*   Updated: 2022/08/09 12:52:00 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int Fixed::getRawBits(void) const
{
	return (_fixed_point);
}

void Fixed::setRawBits(int const raw)
{
	_fixed_point = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->_fixed_point / (1 << Fixed::_frac_bits));
}

int Fixed::toInt(void) const
{
	return (this->_fixed_point >> Fixed::_frac_bits);
}

Fixed& Fixed::operator = (const Fixed &f)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &f)
		_fixed_point = f.getRawBits();
	return (*this);
}

Fixed::Fixed(void) : _fixed_point(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixed_point = num << Fixed::_frac_bits;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixed_point = roundf(num * (1 << Fixed::_frac_bits));
}

Fixed::Fixed(const	Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream &o, const Fixed &f)
{
	return (o << f.toFloat());
}
