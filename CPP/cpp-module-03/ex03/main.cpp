/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:54:22 by fcil              #+#    #+#             */
/*   Updated: 2022/08/11 18:08:45 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main() {

	DiamondTrap	a( "UWU" );

	a.attack( "Conor" );
	a.takeDamage(5);
	a.beRepaired(3);
	a.highFivesGuys();
	a.guardGate();
	a.whoAmI();
}
