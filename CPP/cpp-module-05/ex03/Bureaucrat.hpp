/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 21:39:02 by fcil              #+#    #+#             */
/*   Updated: 2022/09/12 17:09:32 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Form.hpp"

#define LOWEST 150
#define HIGHEST 1

class Form;

class Bureaucrat
{
	private:
		std::string const _name;
		int		_grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &b);
		~Bureaucrat();

		Bureaucrat &operator=(Bureaucrat const &b);
		std::string	getName() const;
		int		getGrade() const;
		
		void	incrementGrade();
		void	decrementGrade();

		void	signForm(Form &form);
		void	executeForm(Form const &form);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char*	what()	const throw()
				{
					return ("Grade is too High.");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char*	what()	const throw()
				{
					return ("Grade is too Low.");
				}
		};
};
std::ostream& operator<<(std::ostream &o, Bureaucrat const &b);
