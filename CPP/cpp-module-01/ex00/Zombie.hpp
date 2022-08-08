/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:11:11 by fcil              #+#    #+#             */
/*   Updated: 2022/08/05 15:11:16 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include<string>
#include<iostream>

class Zombie {
	private:
		std::string	name;

	public:
		Zombie();
		~Zombie();
		void	setName( std::string name );
		void	announce( void );
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );
