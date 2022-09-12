/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:08:24 by fcil              #+#    #+#             */
/*   Updated: 2022/09/12 16:29:59 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"
#include <fstream>

class RobotomyRequestForm : public Form
{
public:
	RobotomyRequestForm();
	virtual ~RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const &src);
	RobotomyRequestForm &operator=(RobotomyRequestForm scf);

	virtual void executeForm() const;
};
