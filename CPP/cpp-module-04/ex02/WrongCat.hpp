/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:33:27 by fcil              #+#    #+#             */
/*   Updated: 2022/08/14 15:12:12 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #pragma once

 #include "WrongAnimal.hpp"

 class WrongCat : public WrongAnimal
 {
 public:
	WrongCat(void);
	WrongCat(WrongCat const &wc);
	virtual ~WrongCat();
	WrongCat	&operator = (WrongCat const &wc);
	void		makeSound(void) const;
};
