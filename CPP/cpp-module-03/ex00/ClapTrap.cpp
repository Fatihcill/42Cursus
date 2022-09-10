/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:58:28 by fcil              #+#    #+#             */
/*   Updated: 2022/09/10 14:23:10 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap:	default constructor has been called" << std::endl;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap:	name constructor has been called" << std::endl;
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::ClapTrap(ClapTrap const &b)
{
	std::cout << "ClapTrap:	copy constructor has been called" << std::endl;
	*this = b;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap:	destructor has been called" << std::endl;
}

ClapTrap&	ClapTrap::operator=(ClapTrap const &b)
{
	std::cout << "ClapTrap:	assignation operator called" << std::endl;
	this->_name = b._name;
	this->_hitPoints = b._hitPoints;
	this->_energyPoints = b._energyPoints;
	this->_attackDamage = b._attackDamage;

	return (*this);
}

void	ClapTrap::attack(std::string const & target)
{
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0)
		std::cout << "ClapTrap:	" << this->_name << ", you already dead" << std::endl;
	else
	{
		std::cout << "ClapTrap:	" << this->_name << " attacks " << target <<
		", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0)
		std::cout << "ClapTrap:	" << this->_name << ", you already dead" << std::endl;
	else
	{
		std::cout << "ClapTrap:	" << this->_name << " took " << amount << " points of damage" << std::endl;
		this->_hitPoints -= amount;	
		if (this->_hitPoints <= 0)
			std::cout << "ClapTrap:	" << "OH NO!! " << this->_name << ", you died..." << std::endl;
	}
}

void 	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0)
		std::cout << "ClapTrap:	" << this->_name << ", you already dead" << std::endl;
	else
	{
		std::cout << "ClapTrap:	" << this->_name << " got " << amount << " of hit points" << std::endl;
		this->_energyPoints--;
		this->_hitPoints += amount;
	}
}

unsigned int	&ClapTrap::getAttackDamage()
{
	return (_attackDamage);
}

void	ClapTrap::setAttackDamage(int AttackDamage)
{
	_attackDamage = AttackDamage;
}

std::string	&ClapTrap::getName()
{
	return (_name);
}

void		ClapTrap::setName(std::string &Name)
{
	_name = Name;
}

int			&ClapTrap::getHitpoints()
{
	return (_hitPoints);
}

void		ClapTrap::setHitpoints(int Hitpoints)
{
	_hitPoints = Hitpoints;
}

unsigned int	&ClapTrap::getEnergyPoints()
{
	return (_energyPoints);
}

void		ClapTrap::setEnergyPoints(int EnergyPoints)
{
	_energyPoints = EnergyPoints;
}

std::ostream	&operator<<(std::ostream &stream, ClapTrap &clapTrap)
{
	stream << "Name: " << clapTrap.getName() << \
	" Hitpoints: " << clapTrap.getHitpoints() << \
	" Energy Points: " << clapTrap.getEnergyPoints() << \
	" Attack Damage: " << clapTrap.getAttackDamage();
	return (stream);
}
