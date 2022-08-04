/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:36:50 by fcil              #+#    #+#             */
/*   Updated: 2022/08/04 16:32:57 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"


std::string Contact::getFirstName()
{
	return (this->_firstName);
}

std::string Contact::getLastName()
{
	return (this->_lastName);
}

std::string Contact::getNickName()
{
	return (this->_nickName);
}

std::string Contact::getDarkestSecret()
{
	return (this->_darkestSecret);
}

std::string Contact::getPhoneNumber()
{
	return (this->_darkestSecret);
}

int Contact::getIsUsed()
{
	return (this->isUsed);
}

void Contact::setFirstName(std::string arg)
{
	this->isUsed = 1;
	this->_firstName = arg;
}

void Contact::setLastName(std::string arg)
{
	this->_lastName = arg;
}

void Contact::setNickName(std::string arg)
{
	this->_nickName = arg;
}

void Contact::setPhoneNumber(std::string arg)
{
	this->_phoneNumber = arg;
}

void Contact::setDarkestSecret(std::string arg)
{
	this->_darkestSecret= arg;	
}

void Contact::printContact()
{
	std::cout << "First name : " << this->_firstName << std::endl;
	std::cout << "Last name: " << this->_lastName << std::endl;
	std::cout << "Nickname: " << this->_nickName << std::endl;
	std::cout << "Phone number: " << this->_phoneNumber << std::endl;
	std::cout << "Darkest secret: " << this->_darkestSecret << std::endl;
}

Contact::Contact()
{
	this->isUsed = 0;	
}

Contact::~Contact()
{
}
