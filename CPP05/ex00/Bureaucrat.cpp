/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 10:31:16 by dboire            #+#    #+#             */
/*   Updated: 2024/08/31 14:33:46 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//Canonical

Bureaucrat::Bureaucrat(){};
Bureaucrat::~Bureaucrat(){};

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
	valid_grade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade){};

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat & other)
{
	this->_grade = other._grade;
	return(*this);
}

//Exceptions

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return("Grade too HIGH");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return("Grade too LOW");
}

void	Bureaucrat::valid_grade(int grade) const
{
	if(grade < 1)
		throw(GradeTooHighException());
	if(grade > 150)
		throw(GradeTooLowException());
}

void	Bureaucrat::increment_grade(int grade)
{
	valid_grade(grade - 1);
	grade--;
}

void	Bureaucrat::decrement_grade(int grade)
{
	valid_grade(grade + 1);
	grade++;
}

const std::string &Bureaucrat::get_name() const
{
	return(this->_name);
}
	
int Bureaucrat::get_grade() const
{
	return(this->_grade);
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &b)
{
	out << b.get_name() << ", bureaucrat grade " << b.get_grade() << ".";
	return(out);
}