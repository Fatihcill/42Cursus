/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:43:08 by fcil              #+#    #+#             */
/*   Updated: 2022/08/04 16:37:09 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>

class Contact
{
private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickName;
	std::string	_phoneNumber;
	std::string	_darkestSecret;
	int			isUsed;
public:
	std::string	getFirstName();
	std::string	getLastName();
	std::string	getNickName();
	std::string	getDarkestSecret();
	std::string	getPhoneNumber();
	int			getIsUsed();

	void		setFirstName(std::string arg);
	void		setLastName(std::string arg);
	void		setNickName(std::string arg);
	void		setPhoneNumber(std::string arg);
	void		setDarkestSecret(std::string arg);

	void		printContact();
	Contact();
	~Contact();
};
