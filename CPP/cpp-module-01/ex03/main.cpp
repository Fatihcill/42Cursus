/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:29:35 by fcil              #+#    #+#             */
/*   Updated: 2022/08/08 12:37:04 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main() {

	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("ABYERK", club);
		bob.attack();
		club.setType("Bomb");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Faith");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("LOVE");
		jim.attack();
	}
}