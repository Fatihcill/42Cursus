/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:54:22 by fcil              #+#    #+#             */
/*   Updated: 2022/09/10 14:46:31 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	FragTrap	FragTrapA("Fatih");
	FragTrap	FragTrapB("Abyerk");

	std::cout << std::endl;

	std::cout << FragTrapA << "\n" << FragTrapB << std::endl;

	FragTrapA.attack("Abyerk");
	FragTrapB.takeDamage(FragTrapA.getAttackDamage());

	std::cout << std::endl;

	std::cout << FragTrapA << "\n" << FragTrapB << std::endl;

	FragTrapB.beRepaired(5);

	std::cout << std::endl;

	std::cout << FragTrapA << "\n" << FragTrapB << std::endl;

	FragTrapB.highFivesGuys();

	std::cout << std::endl;

	return (0);
}
