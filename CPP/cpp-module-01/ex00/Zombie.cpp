/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:10:51 by fcil              #+#    #+#             */
/*   Updated: 2022/09/08 12:59:23 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{}

Zombie::~Zombie()
{
	std::cout << this->name << " killed" << std::endl;	
}

void Zombie::setName(std::string name)
{
	this->name = name;
}

void	Zombie::announce( void )
{
	std::cout << this->name <<  ": BraiiiiiiinnnzzzZ..." << std::endl;
}
