/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:42:20 by fcil              #+#    #+#             */
/*   Updated: 2022/09/12 17:22:47 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	try
	{
		Intern someRandomIntern;
		Intern someRandomIntern2;

		Form* rrf;
		Form* rrf2;
		rrf = someRandomIntern.makeForm("robotomy request", "IDK");
		rrf2 = someRandomIntern2.makeForm("presidential    pardon", "FATIH");
		std::cout << *rrf << std::endl;
		rrf->executeForm();
		rrf2->executeForm();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
