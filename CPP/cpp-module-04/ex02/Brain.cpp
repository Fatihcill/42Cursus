/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 15:20:30 by fcil              #+#    #+#             */
/*   Updated: 2022/09/11 15:19:48 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain:		Default Constructed" << std::endl;
}

Brain::Brain(Brain const & b)
{
	std::cout << "Brain:		Copy Constructed" << std::endl;
	*this = b;
}

Brain::~Brain()
{
	std::cout << "Brain:		Deleted..." << std::endl;
}

Brain& Brain::operator=(Brain const &b)
{
	std::cout << "Brain:		Assigned." << std::endl;
	for (unsigned i = 0; i < 100; ++i)
		this->ideas[i] = b.ideas[i];
	return (*this);
}
