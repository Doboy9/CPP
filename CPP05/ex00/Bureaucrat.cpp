/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 10:31:16 by dboire            #+#    #+#             */
/*   Updated: 2024/07/21 10:31:16 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//Canonical

Bureaucrat::Bureaucrat(){};
Bureaucrat::~Bureaucrat(){};

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	if(this != &other)
	{
		*this = other;
	}
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other)
{
	this->_grade = other._grade;
	return(*this);
}

//Exceptions

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	std::cout << "Grade too HIGH" << std::endl;
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	std::cout << "Grade too LOW" << std::endl;
}

const std::string &Bureaucrat::get_name() const
{
	return(this->_name);
}
	
int Bureaucrat::get_grade() const
{
	return(this->_grade);
}