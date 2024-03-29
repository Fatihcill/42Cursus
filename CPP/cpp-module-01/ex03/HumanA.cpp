/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 12:06:55 by fcil              #+#    #+#             */
/*   Updated: 2022/09/06 18:24:28 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon ): name(name), weapon(weapon) 
{
}

HumanA::~HumanA()
{
}

void HumanA::attack() const
{
	std::cout << this->name << "  attacks with their " << this->weapon.getType() << std::endl;
}
