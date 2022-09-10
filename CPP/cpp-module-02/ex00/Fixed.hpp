/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:02:54 by fcil              #+#    #+#             */
/*   Updated: 2022/09/09 16:02:55 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class	Fixed
{
	private:
			int					_fixed_point;
			static const int	_frac_bits = 8;

	public:
			int		getRawBits(void) const;
			void	setRawBits(int const raw);

			Fixed	&operator = (const Fixed &f);
			Fixed(void);
			Fixed(const	Fixed &f);
			~Fixed(void);
};
