/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:42:20 by fcil              #+#    #+#             */
/*   Updated: 2022/09/12 16:54:24 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	{
		PresidentialPardonForm pp("PP");
	
		Bureaucrat fatih("fatih", 2);
		Bureaucrat abyerk("abyerk", 6);
	
		fatih.signForm(pp);
		abyerk.signForm(pp);
	
		fatih.executeForm(pp);
		abyerk.executeForm(pp);
		std::cout << "--------------------------" << std::endl;
	}
	{
		RobotomyRequestForm rqf("RQF");
		Bureaucrat fatih("fatih", 3);
		Bureaucrat abyerk("abyerk", 6);

		fatih.signForm(rqf);
		abyerk.signForm(rqf);
	
		fatih.executeForm(rqf);
		abyerk.executeForm(rqf);
		std::cout << "--------------------------" << std::endl;
	}
	{
		ShrubberyCreationForm musab("SCF");
		Bureaucrat fatih("fatih", 3);
		Bureaucrat abyerk("abyerk", 6);

		fatih.signForm(musab);
		abyerk.signForm(musab);
	
		fatih.executeForm(musab);
		abyerk.executeForm(musab);
	}
}