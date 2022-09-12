/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                          :+:      :+:    :+:   */
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

class PresidentialPardonForm : public Form
{
public:
	PresidentialPardonForm();
	virtual ~PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const &src);
	PresidentialPardonForm &operator=(PresidentialPardonForm scf);
	virtual Form	*clone(std:: string _target);
	virtual void executeForm() const;
};
