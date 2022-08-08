/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:30:23 by fcil              #+#    #+#             */
/*   Updated: 2022/08/08 11:35:22 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string.h>

class Weapon
{
private:
	std::string			type;

public:
	Weapon(std::string type);
	~Weapon();
	const std::string	&getType(void) const;
	void				setType(const std::string &type);
};
