/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:47:57 by fcil              #+#    #+#             */
/*   Updated: 2022/09/10 15:16:13 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap 
{
private:
	std::string	_name;
public:
	DiamondTrap();
	DiamondTrap(std::string const name);
	DiamondTrap(DiamondTrap const &d);
	virtual ~DiamondTrap();
	DiamondTrap	&operator=(DiamondTrap const &d);
	void		attack(std::string const & target);
	void		whoAmI(void);
};