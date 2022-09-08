/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:30:03 by fcil              #+#    #+#             */
/*   Updated: 2022/09/08 13:27:55 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "[DEBUG]" << std::endl
	<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger."
	<< " I really do!"
	<< std::endl << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[INFO]" << std::endl
	<< "I cannot believe adding extra bacon costs more money."
	<< " You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
	<< std::endl << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[WARNING]" << std::endl
	<< "I think I deserve to have some extra bacon for free."
	<< " I’ve been coming for years whereas you started working here since last month."
	<< std::endl << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ERROR]" << std::endl
	<< "This is unacceptable, I want to speak to the manager now."
	<< std::endl << std::endl;
}

void	Harl::censored(void)
{
	std::cout << "[ Probably complaining about insignificant problems ]"
	<< std::endl << std::endl;
}



static const std::string	levels[] = {
	"DEBUG",
	"INFO",
	"WARNING",
	"ERROR"
};

void	Harl::complain( std::string level )
{
	int filter = 0;
	void (Harl::*f[5])(void) = {&Harl::censored, &Harl::debug, \
								&Harl::info, &Harl::warning, &Harl::error};
	std::string level_set[5] = {"CENSORED", "DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 1 ; i < 5 ; ++i)
		if (level == level_set[i])
			filter = i;
	std::cout << "log: " << filter<<std::endl;
	switch (filter)
	{
		case (0) :
			(this->*(f[0]))();
			break ;
		case (1) :
			(this->*(f[1]))();
		case (2) :
			(this->*(f[2]))();
		case (3) :
			(this->*(f[3]))();
		case (4) :
			(this->*(f[4]))();
		break ;
	}
}