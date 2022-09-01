/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:33:48 by fcil              #+#    #+#             */
/*   Updated: 2022/08/14 15:12:05 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class WrongAnimal
{
protected:
	std::string _type;
public:
	std::string			getType(void) const;
	void				setType(const std::string &type);
	void				makeSound(void) const;
	WrongAnimal			&operator = (const WrongAnimal &wa);
	WrongAnimal(const WrongAnimal &wa);
	WrongAnimal(/* args */);
	virtual ~WrongAnimal();
};
