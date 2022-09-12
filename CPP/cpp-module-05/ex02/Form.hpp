/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:46:52 by fcil              #+#    #+#             */
/*   Updated: 2022/09/12 15:58:01 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool		_signed;
	const int	_gradeToSign;
	const int	_gradeToExecute;
	std::string	target;

public:
	Form(void);
	Form(const std::string name, int signGrade, int execGrade);
	Form(Form const &f);
	virtual ~Form();

	Form 			&operator=(Form const &f);

	std::string		getName() const;
	bool			getSignedResult() const;
	void			setSignedResult(bool signedResult);
	int				getSignGrade(void) const;
	int				getExecGrade(void) const;
	std::string		getFormTarget() const;
	void			setFormTarget(std::string target);

	void			beSigned(Bureaucrat const &b);

	void			execute(Bureaucrat const &executor) const;
	virtual void	executeForm() const = 0;

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char*	what()	const throw()
			{
				return ("<Form> Grade is too High.");
			}
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char*	what()	const throw()
			{
				return ("<Form> Grade is too Low.");
			}
	};	
};

std::ostream &operator<<(std::ostream &o, Form const &f);
