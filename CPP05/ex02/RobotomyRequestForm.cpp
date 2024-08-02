/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:28:33 by dboire            #+#    #+#             */
/*   Updated: 2024/07/30 15:28:33 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"RobotomyRequestForm.hpp"
#include"Bureaucrat.hpp"
#include"AForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::~RobotomyRequestForm(){};

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
: AForm("RobotomyRequestForm", 72, 45), _target(target)
{};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
: AForm(other), _target(other._target)
{};

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if(this != &other)
		AForm::operator=(other);
	return(*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if(this->get_signature() == false)
		throw(AForm::FormNotSignedException());
	if(executor.get_grade() > this->get_grade_executing())
		throw(AForm::GradeTooLowException());
	else
	{
		std::cout << "Drilling noises..." << std::endl;

		std::srand(time(NULL));
		if (std::rand() % 2)
			std::cout << this->get_target() << " has been robotomized successfully." << std::endl;
		else
			std::cout << "The robotomy failed." << std::endl;

	}
}

std::string RobotomyRequestForm::get_target() const
{
	return(this->_target);
}