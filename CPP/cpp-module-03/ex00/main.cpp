/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:54:22 by fcil              #+#    #+#             */
/*   Updated: 2022/08/11 11:35:36 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	clap("Fatih");

	clap.attack("Boo");
	clap.beRepaired(15);
	clap.takeDamage(20);
	clap.takeDamage(20);
	return (0);
}
