/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:54:22 by fcil              #+#    #+#             */
/*   Updated: 2022/09/10 15:22:34 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap	DiamondTrapB("Fatih");

	std::cout << std::endl;

	std::cout << DiamondTrapB << std::endl;

	DiamondTrapB.beRepaired(5);

	std::cout << std::endl;

	std::cout << DiamondTrapB << std::endl;

	DiamondTrapB.highFivesGuys();
	DiamondTrapB.guardGate();
	DiamondTrapB.whoAmI();
	std::cout << std::endl;



	return(0);
}
