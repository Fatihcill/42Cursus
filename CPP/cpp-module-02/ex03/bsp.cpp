/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:39:52 by fcil              #+#    #+#             */
/*   Updated: 2022/09/09 17:35:59 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float	sign(Point &p1, Point &p2, Point &p3)
{

	return ((p1.getX().toFloat() - p3.getX().toFloat()) * (p2.getY().toFloat() - p3.getY().toFloat()) -
	(p2.getX().toFloat() - p3.getX().toFloat()) * (p1.getY().toFloat() - p3.getY().toFloat()));
}

bool bsp(Point &a, Point &b, Point &c, Point &point)
{
	float	A = sign(point, a, b);
	float	B = sign(point, b, c);
	float	C = sign(point, c, a);
	bool	neg = false;
	bool	pos = false;

	neg = ((A < 0) || (B < 0) || (C < 0));
	pos = ((A > 0) || (B > 0) || (C > 0));
	return !(neg && pos);
}
//resource ; 
//https://stackoverflow.com/questions/2049582/how-to-determine-if-a-point-is-in-a-2d-triangle
