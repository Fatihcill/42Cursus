/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 12:22:56 by fcil              #+#    #+#             */
/*   Updated: 2022/09/11 15:12:50 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal
{
protected:
	std::string type;

public:
	virtual Animal	&operator = (const Animal &a);
	Animal(void);
	Animal(const Animal &a);
	virtual ~Animal();

	virtual void 	makeSound() const;
	virtual Brain	*getBrain() const;

	std::string 	getType() const;
	void			setType(const std::string &type);
};
