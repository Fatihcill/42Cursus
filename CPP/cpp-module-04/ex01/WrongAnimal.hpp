/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:33:48 by fcil              #+#    #+#             */
/*   Updated: 2022/09/11 14:55:17 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class WrongAnimal
{
protected:
	std::string type;

public:
	virtual WrongAnimal	&operator = (const WrongAnimal &a);
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal &a);
	virtual ~WrongAnimal();

	virtual void makeSound() const;
	std::string getType() const;
	void		setType(const std::string &type);
};
