/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:11:13 by fcil              #+#    #+#             */
/*   Updated: 2022/09/12 14:56:43 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("null"), _signed(false), _gradeToSign(0), _gradeToExecute(0)
{}

Form::Form(const std::string name, int signGrade, int execGrade) : _name(name), _signed(false), _gradeToSign(signGrade), _gradeToExecute(execGrade)
{
	if (this->_gradeToSign < HIGHEST || this->_gradeToExecute < HIGHEST)
		throw GradeTooHighException();
	if (this->_gradeToSign > LOWEST || this->_gradeToExecute > LOWEST)
		throw GradeTooLowException();
}

Form::Form(Form const &f) : _name(f.getName()), _signed(f.getSignedResult()), _gradeToSign(f.getSignGrade()), _gradeToExecute(f.getExecGrade())
{
	*this = f;	
}

Form::~Form()
{}

Form& Form::operator=(Form const &f)
{
	this->_signed = f.getSignedResult();

	return (*this);
}

std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getSignedResult() const
{
	return(this->_signed);
}

void Form::setSignedResult(bool signedResult)
{
	this->_signed = signedResult;
}

int Form::getSignGrade(void) const
{
	return (this->_gradeToSign);
}

int Form::getExecGrade(void) const
{
	return (this->_gradeToExecute);
}

void Form::beSigned(Bureaucrat const &b)
{
	if (this->getSignGrade() < b.getGrade())
		throw	GradeTooLowException();
	else
		this->_signed = true;
}


std::ostream& operator<<(std::ostream &o, Form const &f)
{
	o << f.getName() << "Form:" << std::endl;
	o << "Status: " << f.getSignedResult() << std::endl;
	o << "Grade To Sign: " << f.getSignGrade() << std::endl;
	o << "Grade To Execute: " << f.getExecGrade() << std::endl;
	return (o);	
}
