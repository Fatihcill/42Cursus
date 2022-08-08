/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 12:51:25 by fcil              #+#    #+#             */
/*   Updated: 2022/08/08 13:05:37 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

class Replace
{
public:
	Replace(/* args */);
	~Replace();
	
	static void	replace(std::string const &filename, char *search, char *replace);
};
