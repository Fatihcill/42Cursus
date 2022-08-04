/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:43:39 by fcil              #+#    #+#             */
/*   Updated: 2022/08/04 16:48:53 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
	std::cout << "PHONEBOOK" << std::endl;
	std::cout << "ADD - adds a new contact" << std::endl;
	std::cout << "SEARCH - opens phonebook" << std::endl;
	std::cout << "EXIT - exits" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "GOODBYE MY LOVE <3" << std::endl;
}

void PhoneBook::add(int i)
{
	std::string	input;

	std::cout << "First Name: ";
	std::getline(std::cin, input);
	_contacts[i].setFirstName(input);
	std::cout << "Last Name: ";
	std::getline(std::cin, input);
	_contacts[i].setLastName(input);
	std::cout << "NickName: ";
	std::getline(std::cin, input);
	_contacts[i].setNickName(input);
	std::cout << "Phone Number: ";
	std::getline(std::cin, input);
	_contacts[i].setPhoneNumber(input);
	std::cout << "Darkest Secret: ";
	std::getline(std::cin, input);
	_contacts[i].setDarkestSecret(input);


}

void PhoneBook::search()
{
	std::string index;
	int			i;

	display();
	std::cout << "index: ";
	std::cin >> index;
	std::istringstream(index) >> i;
	if (i >= 0 && i <= CONT_LEN - 1 && _contacts[i].getIsUsed())
			_contacts[i].printContact();
	else
		std::cout << "Error: Wrong index";
	std::cout << std::endl;
}


void PhoneBook::display()
{
	std::cout << std::setw(10) << "index" << "|";
	std::cout << std::setw(10) << "first name" << "|";
	std::cout << std::setw(10) << "last name" << "|";
	std::cout << std::setw(10) << "nickname" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << std::setw(10) << i << "|";
		this->printCheck(_contacts[i].getFirstName());
		this->printCheck(_contacts[i].getLastName());
		this->printCheck(_contacts[i].getNickName());
		std::cout << std::endl;
	}
}

void PhoneBook::printCheck(std::string str)
{
	if (str.length() > 10)
			std::cout << std::setw(10) << str.substr(0, 9) + "." << "|" ;
	else
			std::cout << std::setw(10) << str << "|";
}
