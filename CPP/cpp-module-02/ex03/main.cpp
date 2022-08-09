/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:55:02 by fcil              #+#    #+#             */
/*   Updated: 2022/08/09 17:28:58 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void)
{
	Point		point(Fixed(-4), Fixed(10));
	Point		a(Fixed(-5), Fixed(10));
	Point		b(Fixed(5), Fixed(10));
	Point		c(Fixed(0), Fixed(0));

	if (bsp(a, b, c, point))
		std::cout << "it's bsp" << std::endl; 
	else
		std::cout << "it's NOT bsp" << std::endl; 

	return (0);
}
