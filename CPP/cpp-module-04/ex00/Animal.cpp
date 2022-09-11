/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 12:27:34 by fcil              #+#    #+#             */
/*   Updated: 2022/09/11 14:13:15 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	this->setType("Animal");
	std::cout << "Animal:		Default Constructed" << std::endl;
}

Animal::Animal(const Animal &a)
{
	*this = a;
	std::cout << "Animal:		Copy Constructed" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal:		Deleted..." << std::endl;
}

Animal&	Animal::operator=(const Animal &a)
{
	this->setType(a.getType());
	std::cout << "Animal:		Assigned." << std::endl;
	return (*this);
}

std::string Animal::getType(void) const
{
	return (this->type);
}

void Animal::setType(const std::string &type)
{
	this->type = type;
}

void Animal::makeSound(void) const
{
	std::cout << "Animal:		???" << std::endl;
}
