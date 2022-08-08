/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:35:44 by fcil              #+#    #+#             */
/*   Updated: 2022/08/08 12:29:57 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type): type(type)
{
}

Weapon::~Weapon()
{	
}

const std::string& Weapon::getType(void) const
{
	return (this->type);
}

void Weapon::setType(const std::string &type)
{
	this->type = type;	
}
