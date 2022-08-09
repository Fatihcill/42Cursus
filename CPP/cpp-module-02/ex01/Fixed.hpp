/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:02:54 by fcil              #+#    #+#             */
/*   Updated: 2022/08/09 12:39:13 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class	Fixed
{
	private:
			int					_fixed_point;
			static const int	_frac_bits = 8;

	public:
			int		getRawBits(void) const;
			void	setRawBits(int const raw);
			float	toFloat(void) const;
			int		toInt(void) const;

			Fixed	&operator = (const Fixed &f);
			Fixed(void);
			Fixed(const	Fixed &f);
			Fixed(const int num);
			Fixed(const float num);
			~Fixed(void);
};
std::ostream	&operator<<(std::ostream &o, const Fixed &f);
