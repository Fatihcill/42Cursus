/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:00:00 by fcil              #+#    #+#             */
/*   Updated: 2022/09/09 16:54:53 by fcil             ###   ########.fr       */
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

Fixed::Fixed(void) : _fixed_point(0)
{
}

Fixed::Fixed(const int num)
{
	this->_fixed_point = num << Fixed::_frac_bits;
}

Fixed::Fixed(const float num)
{
	this->_fixed_point = roundf(num * (1 << Fixed::_frac_bits));
}

Fixed::Fixed(const	Fixed &f)
{
	*this = f;
}

Fixed::~Fixed(void)
{
}

Fixed& Fixed::operator = (const Fixed &f)
{
	if (this != &f)
		_fixed_point = f.getRawBits();
	return (*this);
}

bool Fixed::operator>(Fixed const &f)
{
	return(this->_fixed_point > f._fixed_point);
}

bool Fixed::operator<(Fixed const &f)
{
	return(this->_fixed_point < f._fixed_point);
}

bool Fixed::operator>=(Fixed const &f)
{
	return(this->_fixed_point >= f._fixed_point);
}

bool Fixed::operator<=(Fixed const &f)
{
	return(this->_fixed_point <= f._fixed_point);
}

bool Fixed::operator==(Fixed const &f)
{
	return(this->_fixed_point == f._fixed_point);
}

bool Fixed::operator!=(Fixed const &f)
{
	return(this->_fixed_point != f._fixed_point);
}

Fixed Fixed::operator-(Fixed const &f)
{
	this->_fixed_point -= f.getRawBits();
	return (*this);
}

Fixed Fixed::operator/(Fixed const &f)
{
	this->_fixed_point = (this->toFloat() / f.toFloat()) * (1 << _frac_bits);
	return (*this);
}

Fixed Fixed::operator*(Fixed const &f)
{
	this->_fixed_point = (this->toFloat() * f.toFloat()) * (1 << _frac_bits);
	return (*this);
}

Fixed Fixed::operator+(Fixed const &f)
{
	this->_fixed_point += f._fixed_point;
	return (*this);
}

Fixed& Fixed::operator--(void)
{
	this->_fixed_point--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed	tmp(*this);

	this->_fixed_point--;
	return (tmp);
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if ((Fixed)a < (Fixed)b)
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if ((Fixed)a > (Fixed)b)
		return (a);
	return (b);

}

Fixed const& Fixed::min(Fixed const &a, Fixed const &b)
{
	if ((Fixed)a < (Fixed)b)
		return (a);
	return (b);
}

Fixed const& Fixed::max(Fixed const &a, Fixed const &b)
{
	if ((Fixed)a > (Fixed)b)
		return (a);
	return (b);
}

Fixed Fixed::operator++(int)
{
	Fixed	tmp(*this);

	this->_fixed_point++;
	return (tmp);
}

Fixed& Fixed::operator++(void)
{
	this->_fixed_point++;
	return (*this);
}

std::ostream& operator<<(std::ostream &o, const Fixed &f)
{
	return (o << f.toFloat());
}
