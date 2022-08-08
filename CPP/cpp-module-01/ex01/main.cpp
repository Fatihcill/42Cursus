/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 10:24:37 by fcil              #+#    #+#             */
/*   Updated: 2022/08/08 10:26:21 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	int		numberofzombie;
	Zombie	*horde;
	
	numberofzombie = 8;
	horde = zombieHorde(numberofzombie, "faith");
	for (int i = 0; i < numberofzombie; i++)
	{
		horde[i].announce();
	}
}
