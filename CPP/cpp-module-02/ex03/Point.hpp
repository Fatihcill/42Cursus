/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:32:59 by fcil              #+#    #+#             */
/*   Updated: 2022/08/09 17:19:42 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class	Point {

	private:
		Fixed const	_x;
		Fixed const	_y;

	public:
		Point(void);
		Point(Point const &b);
		Point(Fixed const &x, Fixed const &y);

		Point		&operator=(Point const &b);
		Fixed const	&getX(void);
		Fixed const	&getY(void);

		~Point();
};

bool	bsp(Point &a, Point &b, Point &c, Point &point);
