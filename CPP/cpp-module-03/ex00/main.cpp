/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:54:22 by fcil              #+#    #+#             */
/*   Updated: 2022/09/10 14:20:42 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{

	ClapTrap	ClaptrapA("ClaptrapA");
	ClapTrap	ClaptrapB("ClaptrapB");

	ClapTrap	ClapTrapC(ClaptrapA);
	std::cout << ClapTrapC << std::endl;

	std::cout << std::endl;

	std::cout << ClaptrapA << "\n" << ClaptrapB << std::endl;

	ClaptrapA.attack("ClaptrapB");
	ClaptrapB.takeDamage(ClaptrapA.getAttackDamage());

	std::cout << std::endl;

	std::cout << ClaptrapA << "\n" << ClaptrapB << std::endl;

	ClaptrapB.beRepaired(5);

	std::cout << std::endl;

	std::cout << ClaptrapA << "\n" << ClaptrapB << std::endl;
	return (0);
}
