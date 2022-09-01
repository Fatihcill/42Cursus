/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 12:22:56 by fcil              #+#    #+#             */
/*   Updated: 2022/08/14 15:12:27 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "string.h"
#include "iostream"

class Animal
{
protected:
	std::string _type;

public:
	std::string			getType(void) const;
	void				setType(const std::string &type);
	virtual void		makeSound(void) const;
	Animal				&operator = (const Animal &a);
	Animal(void);
	Animal(const Animal &a);
	virtual ~Animal();
};
