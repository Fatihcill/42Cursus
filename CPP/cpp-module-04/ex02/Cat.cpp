/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 12:41:53 by fcil              #+#    #+#             */
/*   Updated: 2022/09/11 16:04:16 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Cat:		Default Constructed" << std::endl;
	this->setType("Cat");
	this->brain = new Brain();
}

Cat::Cat(Cat const &c)
{
	std::cout << "Cat:		Copy Constructed" << std::endl;
	this->brain = new Brain();
	*this = c;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat:		Deleted..." << std::endl;
}

Cat& Cat::operator = (Cat const &c)
{
	std::cout << "Cat:		Assigned." << std::endl;
	this->setType(c.getType());
	*(this->brain) = *(c.brain);
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "Cat:		Meow Meow" << std::endl;
}

Brain	*Cat::getBrain() const
{
	return (this->brain);
}
