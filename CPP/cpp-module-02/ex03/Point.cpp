/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:33:43 by fcil              #+#    #+#             */
/*   Updated: 2022/08/09 13:41:38 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{
}

Point::Point(Point const &b)
{
	*this = b;
}

Point::Point(Fixed const &x, Fixed const &y): _x(x), _y(y)
{
}

Point& Point::operator=(Point const &b)
{
	(Fixed)this->_x = (Fixed)b._x;
	(Fixed)this->_y = (Fixed)b._y;

	return (*this);
}

Fixed const& Point::getX(void)
{
	return (this->_x);
}

Fixed const& Point::getY(void)
{
	return (this->_y);
}

Point::~Point()
{
}
