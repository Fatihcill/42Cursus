/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 12:00:32 by fcil              #+#    #+#             */
/*   Updated: 2022/09/12 15:15:06 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	this->_grade = LOWEST;	
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < HIGHEST)
		throw Bureaucrat::GradeTooHighException();
	if (grade > LOWEST)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &b) : _name(b.getName()), _grade(b.getGrade())
{
	*this = b;
}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &b)
{
	this->_grade = b.getGrade();

	return (*this);
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 < HIGHEST)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > LOWEST)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;

}

void Bureaucrat::signForm(Form &form)
{
	if (form.getSignGrade() >= this->getGrade())
	{
		form.setSignedResult(true);
		std::cout << "<" << this->getName() << "> signed <" <<
		form.getName() << ">" << std::endl; 
	}
	else
		std::cout << "<" << this->getName() << "> cannot sign <" <<
		form.getName() << "> because <the bureaucrat's grade is lower than " 
		"the form's grade to sign>."<< std::endl;
}

std::ostream& operator<<(std::ostream &o, Bureaucrat const &b)
{
	o << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return (o);
}
