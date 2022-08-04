/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:25:19 by fcil              #+#    #+#             */
/*   Updated: 2022/08/04 16:51:17 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main()
{
	PhoneBook	phonebook;
	std::string	input;
	int			i;

	i = 0;
	while (1)
	{
		std::cout << ">";
		std::getline(std::cin, input);
		if (input == "EXIT")
			return (0);
		else if (input == "SEARCH")
			phonebook.search();
		else if (input == "ADD")
		{
			phonebook.add(i);
			i++;
			if (i >= 8)
				i = 0;;
		}
		std::cout << std::endl;
	}
	return (0);
}
