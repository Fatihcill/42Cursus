/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:42:26 by fcil              #+#    #+#             */
/*   Updated: 2022/08/04 16:16:55 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "contact.hpp"
#define CONT_LEN 8

class PhoneBook
{
private:
	Contact _contacts[CONT_LEN];
public:
	PhoneBook();
	~PhoneBook();

	void	add(int i);
	void	search();
	void	display();
	void	printCheck(std::string str);
};
