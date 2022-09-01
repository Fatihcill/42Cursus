/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 12:41:53 by fcil              #+#    #+#             */
/*   Updated: 2022/08/14 14:32:07 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	this->setType("Cat");
	std::cout << "Cat:	Default Constructed" << std::endl;
}

Cat::Cat(Cat const &c) : Animal()
{
	*this = c;
	std::cout << "Cat:	Copy Constructed" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat:	Deleted..." << std::endl;
}

Cat& Cat::operator = (Cat const &c)
{
	this->_type = c.getType();
	std::cout << "Cat:	Assigned." << std::endl;
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "Cat:	Meow Meow" << std::endl;
}
