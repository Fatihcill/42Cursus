/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:26:36 by fcil              #+#    #+#             */
/*   Updated: 2022/09/11 16:01:08 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << "Dog:		Default Constructed" << std::endl;
	this->setType("Dog");
	this->brain = new Brain();
}

Dog::Dog(Dog const &d) : Animal(d)
{
	std::cout << "Dog:		Copy Constructed" << std::endl;
	this->brain = new Brain();
	*this = d;
}

Dog::~Dog()
{
	delete (this->brain);
	std::cout << "Dog:		Deleted..." << std::endl;
}

Dog& Dog::operator = (Dog const &d)
{
	std::cout << "Dog:		Assigned." << std::endl;
	this->setType(d.getType());
	*(this->brain) = *(d.brain);
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "Dog:		Hav Hav" << std::endl;
}

Brain	*Dog::getBrain() const
{
	return (this->brain);
}
