/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:35:59 by fcil              #+#    #+#             */
/*   Updated: 2022/09/11 14:57:35 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

std::string WrongAnimal::getType(void) const
{
	return (this->type);
}

void WrongAnimal::setType(const std::string &type)
{
	this->type = type;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal:	Can't make sound Yet " << std::endl;
}

WrongAnimal& WrongAnimal::operator = (const WrongAnimal &wa)
{
	this->setType(wa.getType()); 
	std::cout << "WrongAnimal:	Assigned." << std::endl;
	return (*this);
}

WrongAnimal::WrongAnimal(const WrongAnimal &wa)
{
	this->setType(wa.getType());
	std::cout << "WrongAnimal:	Default Constructed" << std::endl;
}

WrongAnimal::WrongAnimal(void)
{
	this->setType("WrongAnimal");
	std::cout << "WrongAnimal:	Default Constructed" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal:	Deleted..." << std::endl;
}
