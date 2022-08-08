/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 12:07:27 by fcil              #+#    #+#             */
/*   Updated: 2022/08/08 12:29:01 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanB
{
private:
	std::string	name;
	Weapon		*weapon;

public:
	HumanB(std::string name);
	~HumanB();

	void	attack() const;
	void	setWeapon(Weapon &weapon);
};
