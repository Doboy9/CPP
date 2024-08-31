/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:01:06 by dboire            #+#    #+#             */
/*   Updated: 2024/07/29 15:01:06 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"AForm.hpp"

AForm::AForm() : _name("default"), _grade_signing(0), _grade_executing(0){};

AForm::AForm(const std::string &name, int grade_signing, int grade_executing) : _name(name), _grade_signing(grade_signing), _grade_executing(grade_executing)
{
	_signed = false;
	valid_grade(grade_signing);
	valid_grade(grade_executing);
}

AForm::~AForm(){};

AForm::AForm(const AForm &other) : _name(other._name), _grade_signing(other._grade_signing), _grade_executing(other._grade_executing)
{
	_signed = other.get_signature();
}

AForm	&AForm::operator=(const AForm &other)
{
	this->_signed = other._signed;
	return(*this);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return("Grade too HIGH");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return("Grade too LOW");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return("Form is not currently signed");
}

void	AForm::valid_grade(int grade) const
{
	if(grade < 1)
		throw(GradeTooHighException());
	if(grade > 150)
		throw(GradeTooLowException());
}

//Getters

int AForm::get_grade_signing() const
{
	return(this->_grade_signing);
}

int AForm::get_grade_executing() const
{
	return(this->_grade_executing);
}

const std::string &AForm::get_name() const
{
	return(this->_name);
}

bool AForm::get_signature() const
{
	return(this->_signed);
}

void AForm::beSigned(Bureaucrat &b)
{
	if(b.get_grade() <= this->get_grade_signing())
		this->_signed = true;
	else
		throw(GradeTooLowException());
}

std::ostream& operator<<(std::ostream &out, const AForm &Aform)
{
	out << "AForm name :" << Aform.get_name() 
	<< " AForm signing grade : " << Aform.get_grade_signing() 
	<< " AForm executing grade : " << Aform.get_grade_executing();
	return(out);
}