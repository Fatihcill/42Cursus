/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:10:36 by fcil              #+#    #+#             */
/*   Updated: 2022/09/12 16:39:14 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
Form("RobotomyRequestForm", 72, 45)
{}

RobotomyRequestForm::~RobotomyRequestForm() 
{}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
Form("RobotomyRequestForm", 72, 45)
{
	this->setFormTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) :
Form(src.getName(), src.getSignGrade(), src.getExecGrade())
{
	*this = src;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm scf)
{
	this->setSignedResult(scf.getSignedResult());
	this->setFormTarget(scf.getFormTarget());

	return (*this);
}

void RobotomyRequestForm::executeForm() const
{
	srand(time(NULL));
	if (rand() % 2 == 0) {
		std::cout << "Bzzzztttt...." << std::endl;
		std::cout << this->getFormTarget() << " has been robotomized successfully." << std::endl;
	}
	else {
		std::cout << this->getFormTarget() << " robotomy failed." << std::endl;
	}
}

Form *RobotomyRequestForm::clone(std::string _target)
{
	return (new RobotomyRequestForm(_target));
}
