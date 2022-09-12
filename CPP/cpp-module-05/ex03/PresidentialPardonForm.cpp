/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:10:36 by fcil              #+#    #+#             */
/*   Updated: 2022/09/12 17:10:17 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
Form("PresidentialPardonForm", 25, 5)
{}

PresidentialPardonForm::~PresidentialPardonForm() 
{}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
Form("PresidentialPardonForm", 25, 5)
{
	this->setFormTarget(target);
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) :
Form(src.getName(), src.getSignGrade(), src.getExecGrade())
{
	*this = src;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm scf)
{
	this->setSignedResult(scf.getSignedResult());
	this->setFormTarget(scf.getFormTarget());

	return (*this);
}

void PresidentialPardonForm::executeForm() const
{
	std::cout << this->getFormTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

Form *PresidentialPardonForm::clone(std::string _target) 
{
	return (new PresidentialPardonForm(_target));
}
