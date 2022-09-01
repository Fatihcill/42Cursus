/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 12:36:39 by fcil              #+#    #+#             */
/*   Updated: 2022/08/14 15:27:27 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain	*brain;

public:
	Cat(void);
	Cat(Cat const &c);
	virtual ~Cat();
	Cat		&operator = (Cat const &c);
	void	makeSound(void) const;
};
