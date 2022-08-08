/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:29:57 by fcil              #+#    #+#             */
/*   Updated: 2022/08/08 16:05:16 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char const *argv[])
{
	Harl	h;

	if (argc != 2)
		std::cout << "Invalid Arguments" << std::endl;
	else
		h.complain(argv[1]);
	return (0);
}