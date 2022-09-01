/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 15:20:30 by fcil              #+#    #+#             */
/*   Updated: 2022/08/14 15:24:43 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain:	Default Constructed" << std::endl;
}

Brain::Brain(Brain const & b)
{
	*this = b;
	std::cout << "Brain:	Copy Constructed" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain:	Deleted..." << std::endl;
}

Brain& Brain::operator=(Brain const &b)
{
	std::string *ideas = b.getIdeas();
	for (int i = 0; i < N_IDEAS; i++)
		this->ideas[i] = ideas[i];
	return *this;	std::cout << "Brain:	Assigned." << std::endl;
	return (*this);
}

std::string* Brain::getIdeas() const
{
	return (std::string *)this->ideas;	
}
