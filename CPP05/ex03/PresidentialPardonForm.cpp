/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:28:23 by dboire            #+#    #+#             */
/*   Updated: 2024/07/30 15:28:23 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"PresidentialPardonForm.hpp"
#include"Bureaucrat.hpp"
#include"AForm.hpp"

PresidentialPardonForm::~PresidentialPardonForm(){};

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
: AForm("PresidentialPardonForm", 25, 5), _target(target)
{};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
: AForm(other), _target(other._target)
{};

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if(this != &other)
		AForm::operator=(other);
	return(*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if(this->get_signature() == false)
		throw(AForm::FormNotSignedException());
	if(executor.get_grade() > this->get_grade_executing())
		throw(AForm::GradeTooLowException());
	else
		std::cout << this->get_target() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::string PresidentialPardonForm::get_target() const
{
	return(this->_target);
}