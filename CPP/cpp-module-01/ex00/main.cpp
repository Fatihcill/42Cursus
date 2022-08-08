/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:15:24 by fcil              #+#    #+#             */
/*   Updated: 2022/08/05 15:28:12 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie*	newzombie = newZombie("FATIH");
	newzombie->announce();
	randomChump("abyerk");

	delete newzombie;
}
