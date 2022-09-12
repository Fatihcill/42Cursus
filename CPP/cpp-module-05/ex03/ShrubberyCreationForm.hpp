/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:08:24 by fcil              #+#    #+#             */
/*   Updated: 2022/09/12 17:13:01 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm : public Form
{
public:
	ShrubberyCreationForm();
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const &src);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm scf);

	virtual Form	*clone(std:: string _target);
	virtual void executeForm() const;
};
