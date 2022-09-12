/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:42:20 by fcil              #+#    #+#             */
/*   Updated: 2022/09/12 13:01:50 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat f("fatih", 0);
	}
	catch(const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat a("abyerk", 200);
	}
	catch(const std::exception& e)
	{
		std::cout << "uwu";
		std::cerr << e.what() << std::endl;
	}
}