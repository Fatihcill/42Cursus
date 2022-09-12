/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 23:54:35 by fcil              #+#    #+#             */
/*   Updated: 2022/09/13 00:27:51 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

static bool	is_valid(std::string &str)
{
	size_t	i;
	char	c;
    std::ostringstream ss;

	if (is_pseudo_literal(str))
		return (true);
	if (str.length() == 1 && isalpha(str[0]))
	{
		ss << static_cast<int>(str[0]);
		str = ss.str();
		return (true);
	}
	for (i = 0; i < str.size(); i++)
	{
		c = str[i];
		if (!isdigit(c) && c != '-' && c != '+' && c != 'f' && c != '.')
			return (false);
	}
	return (true);
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Bad number of args" << std::endl;
		return (0);
	}
	std::string str = (std::string)av[1];
	if (is_valid(str)){
		conversion_of_scalar_types(str);
	}
	else
		std::cerr << "Invalid" << std::endl;
}