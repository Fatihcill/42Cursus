/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:54:22 by fcil              #+#    #+#             */
/*   Updated: 2022/09/10 15:17:22 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	ClapTrap	ClapTrapA("Abyerk");
	DiamondTrap	DiamondTrapB("Fatih");

	std::cout << std::endl;

	std::cout << ClapTrapA << "\n" << DiamondTrapB << std::endl;

	ClapTrapA.attack("Abyerk");
	DiamondTrapB.takeDamage(ClapTrapA.getAttackDamage());

	std::cout << std::endl;

	std::cout << ClapTrapA << "\n" << DiamondTrapB << std::endl;

	DiamondTrapB.beRepaired(5);

	std::cout << std::endl;

	std::cout << ClapTrapA << "\n" << DiamondTrapB << std::endl;

	DiamondTrapB.highFivesGuys();
	DiamondTrapB.guardGate();
	DiamondTrapB.whoAmI();
	std::cout << std::endl;



	return(0);
}
