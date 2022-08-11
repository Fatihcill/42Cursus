/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:54:22 by fcil              #+#    #+#             */
/*   Updated: 2022/08/11 17:43:54 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
	FragTrap	a( "Potter" );

	a.attack( "Malfoy" );
	a.takeDamage(100);
	a.beRepaired(3);
	a.highFivesGuys();
	return (0);
}
