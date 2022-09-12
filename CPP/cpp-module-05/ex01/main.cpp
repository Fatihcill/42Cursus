/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:42:20 by fcil              #+#    #+#             */
/*   Updated: 2022/09/12 15:16:00 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
    try 
    {
        Form form1("Player Contract", 150, 150);
        Bureaucrat bCrat1("Richarlison", 1);
        form1.beSigned(bCrat1);
        std::cout << "Welcome to the Club" << std::endl;
        bCrat1.incrementGrade(); 
    }
    catch (std::exception &e) 
    {
        std::cout << "About to print the exception" << std::endl;
        std::cout << e.what() << std::endl;
    }
  
    std::cout  << "<<<<<<<<<<<<>>>>>>>>>>>" << std::endl;
    try 
    {
        Form form1("Drivers License", 1, 1);
        std::cout << form1;
        Bureaucrat bCrat1("Caitlyn Jenner", 150);
        form1.beSigned(bCrat1);
    }
    catch (std::exception &e) 
    {
        std::cout << "About to print the exception" << std::endl;
        std::cout << e.what() << std::endl;
    }
    std::cout << "<<<<<<<<<<<<<>>>>>>>>>>>>>" << std::endl;
	Form form1("uwu", 60, 60);
	std::cout << form1;
	Bureaucrat bCrat1("aa", 50);
	Bureaucrat bCrat2("bb", 120);
	bCrat1.signForm(form1);
	std::cout << form1;
	bCrat2.signForm(form1);
    std::cout << "<<<<<<<<<<<<<>>>>>>>>>>>>>" << std::endl;
}