/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 12:27:34 by fcil              #+#    #+#             */
/*   Updated: 2022/08/14 14:18:09 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

std::string Animal::getType(void) const
{
	return (this->_type);
}

void Animal::setType(const std::string &type)
{
	this->_type = type;
}

void Animal::makeSound(void) const
{
	std::cout << "Animal:	Can't make sound Yet " << std::endl;
}

Animal& Animal::operator = (const Animal &a)
{
	this->_type = a.getType();
	std::cout << "Animal:	Assigned." << std::endl;
	return (*this);
}

Animal::Animal(void)
{
	this->setType("Animal");
	std::cout << "Animal:	Default Constructed" << std::endl;
}

Animal::Animal(const Animal &a)
{
	*this = a;
	std::cout << "Animal:	Copy Constructed" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal:	Deleted..." << std::endl;
}
