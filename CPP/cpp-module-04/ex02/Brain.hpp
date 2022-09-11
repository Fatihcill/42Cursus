/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 15:17:17 by fcil              #+#    #+#             */
/*   Updated: 2022/09/11 15:16:05 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#define N_IDEAS 100
class Brain
{
private:

public:
	Brain();
	Brain(Brain const & b);
	virtual ~Brain();
	Brain 		&operator=(Brain const & b);
	std::string	ideas[N_IDEAS];
};
