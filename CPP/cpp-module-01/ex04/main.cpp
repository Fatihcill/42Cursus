/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 12:54:35 by fcil              #+#    #+#             */
/*   Updated: 2022/08/08 12:56:09 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Invalid number of arg" << std::endl;
		return (1);
	}
	Replace::replace(argv[1], argv[2], argv[3]);
	return (0);
}
