/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:10:36 by fcil              #+#    #+#             */
/*   Updated: 2022/09/12 16:30:03 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm() :
Form("ShrubberyCreationForm", 145, 137)
{}

ShrubberyCreationForm::~ShrubberyCreationForm() 
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
Form("ShrubberyCreationForm", 145, 137)
{
	this->setFormTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) :
Form(src.getName(), src.getSignGrade(), src.getExecGrade())
{
	*this = src;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm scf)
{
	this->setSignedResult(scf.getSignedResult());
	this->setFormTarget(scf.getFormTarget());

	return (*this);
}

void ShrubberyCreationForm::executeForm() const
{
	std::string target = this->getFormTarget();

	std::ofstream outFile(target + "_shrubbery");
	if (!outFile)
	{
		std::cerr << "can't open/create" << this->getFormTarget() + "_shrubbery" << std::endl;
		return;
	}
	outFile << "            # #### ####\n"
			   "        ### \\/#|### |/####\n"
			   "        ##\\/#/ \\||/##/_/##/_#\n"
			   "       ###  \\/###|/ \\/ # ###\n"
			   "    ##_\\_#\\_\\## | #/###_/_####\n"
			   "    ## #### # \\ #| /  #### ##/##\n"
			   "    __#_--###`  |{,###---###-~\n"
			   "                \\ }{\n"
			   "                }}{\n"
			   "                }}{\n"
			   "        canodis {{}\n"
			   "        , -=-~{ .-^- _\n"
			   "                `}\n"
			   "                 {"
			<< std::endl;	
}
