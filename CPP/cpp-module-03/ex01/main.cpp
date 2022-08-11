/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:54:22 by fcil              #+#    #+#             */
/*   Updated: 2022/08/11 11:58:31 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap	trap("Fatih");

	trap.attack("Boo");
	trap.beRepaired(15);
	trap.takeDamage(20);
	trap.takeDamage(20);
	return (0);
}
