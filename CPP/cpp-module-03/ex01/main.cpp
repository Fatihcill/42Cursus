/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:54:22 by fcil              #+#    #+#             */
/*   Updated: 2022/09/10 14:43:09 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap	ScavTrapA("Fatih");
	ScavTrap	ScavTrapB("Abyerk");

	std::cout << std::endl;

	std::cout << ScavTrapA << "\n" << ScavTrapB << std::endl;

	ScavTrapA.attack("Abyerk");
	ScavTrapB.takeDamage(ScavTrapA.getAttackDamage());

	std::cout << std::endl;

	std::cout << ScavTrapA << "\n" << ScavTrapB << std::endl;

	ScavTrapB.beRepaired(5);

	std::cout << std::endl;

	std::cout << ScavTrapA << "\n" << ScavTrapB << std::endl;

	ScavTrapB.guardGate();

	std::cout << std::endl;

	return (0);
}
