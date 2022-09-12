/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:46:52 by fcil              #+#    #+#             */
/*   Updated: 2022/09/12 15:58:01 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
private:
	Form *forms[3];
public:
	Intern();
	Intern(Intern const &copy);
	Intern &operator=(Intern const &src);
	~Intern();
	Form *makeForm(std::string _form, std::string _target);
	class FormNotFound : public std::exception
	{
	public:
		const char *what() const throw();
	};
};
