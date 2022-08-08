/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 10:15:41 by fcil              #+#    #+#             */
/*   Updated: 2022/08/08 10:26:57 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie* horde;
	int		i;

	i = -1;
	horde = new Zombie[N];
	while (++i < N)
	{
		horde[i].setName(name);
	}
	return (horde);
}
