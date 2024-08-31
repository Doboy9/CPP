/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:22:08 by dboire            #+#    #+#             */
/*   Updated: 2024/08/31 15:38:31 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(){};

Intern::~Intern()
{
	
};


AForm *Intern::RobotomyRequest(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::ShrubberyCreation(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::PresidentialPardon(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

AForm * Intern::makeForm(std::string name, std::string target)
{
	AForm* (Intern::*ptr[])(const std::string &) = {&Intern::RobotomyRequest, &Intern::ShrubberyCreation, &Intern::PresidentialPardon};
	std::string array[] = {"robotomy request", "shrubbery creation", "presidential pardon"};
	
	for(int i = 0; i < 3; i++)
	{
		if(array[i] == name)
		{
			std::cout << "Intern creates " << name << " form" << std::endl;
			return (this->*ptr[i])(target);
		}
	}
	std::cout << "Error: Form name \"" << name << "\" not recognized." << std::endl;
	return NULL;
}