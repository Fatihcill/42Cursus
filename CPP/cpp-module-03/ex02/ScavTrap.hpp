/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:37:44 by fcil              #+#    #+#             */
/*   Updated: 2022/08/11 17:25:42 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string.h>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:

public:
	void attack(const std::string &target);
	void guardGate(void) const;

	ScavTrap &operator=(const ScavTrap &s);

	ScavTrap(void);
	ScavTrap(const std::string &name);
	ScavTrap(const ScavTrap &s);
	virtual ~ScavTrap(void);
};
