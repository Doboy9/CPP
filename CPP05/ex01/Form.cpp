/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:01:06 by dboire            #+#    #+#             */
/*   Updated: 2024/07/29 15:01:06 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Form.hpp"


Form::Form(const std::string &name, int grade_signing, int grade_executing) : _name(name), _grade_signing(grade_signing), _grade_executing(grade_executing)
{
	_signed = false;
	valid_grade(grade_signing);
	valid_grade(grade_executing);
}

Form::~Form(){};

const char *Form::GradeTooHighException::what() const throw()
{
	return("Grade too HIGH");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return("Grade too LOW");
}

void	Form::valid_grade(int grade) const
{
	if(grade < 1)
		throw(GradeTooHighException());
	if(grade > 150)
		throw(GradeTooLowException());
}

//Getters

int Form::get_grade_signing() const
{
	return(this->_grade_signing);
}

int Form::get_grade_executing() const
{
	return(this->_grade_executing);
}

const std::string &Form::get_name() const
{
	return(this->_name);
}

bool Form::get_signature() const
{
	return(this->_signed);
}

void Form::beSigned(Bureaucrat &b)
{
	if(b.get_grade() <= this->get_grade_signing())
		this->_signed = true;
	else
		throw(GradeTooLowException());
}

std::ostream& operator<<(std::ostream &out, const Form &form)
{
	out << "Form name :" << form.get_name() 
	<< " Form signing grade : " << form.get_grade_signing() 
	<< " Form executing grade : " << form.get_grade_executing();
	return(out);
}