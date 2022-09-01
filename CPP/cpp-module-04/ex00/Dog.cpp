/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:26:36 by fcil              #+#    #+#             */
/*   Updated: 2022/08/14 14:32:15 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	this->setType("Dog");
	std::cout << "Dog:	Default Constructed" << std::endl;
}

Dog::Dog(Dog const &d) : Animal()
{
	*this = d;
	std::cout << "Dog:	Copy Constructed" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog:	Deleted..." << std::endl;
}

Dog& Dog::operator = (Dog const &d)
{
	this->_type = d.getType();
	std::cout << "Dog:	Assigned." << std::endl;
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "Dog:	Hav Hav" << std::endl;
}
