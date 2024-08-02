/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:28:43 by dboire            #+#    #+#             */
/*   Updated: 2024/07/30 15:28:43 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ShrubberyCreationForm.hpp"
#include"Bureaucrat.hpp"
#include"AForm.hpp"
#include <cstdlib>
#include <ctime>

ShrubberyCreationForm::~ShrubberyCreationForm(){};

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
: AForm(other), _target(other._target)
{};

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if(this != &other)
		AForm::operator=(other);
	return(*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if(this->get_signature() == false)
		throw(AForm::FormNotSignedException());
	if(executor.get_grade() > this->get_grade_executing())
		throw(AForm::GradeTooLowException());
	else
	{
		std::ofstream outfile;
		std::string	target;

		target = get_target() + "_shrubbery";
		outfile.open(target.c_str());

		 outfile << "       _-_\n"
                   "    /~~   ~~\\\n"
                   " /~~         ~~\\\n"
                   "{               }\n"
                   " \\  _-     -_  /\n"
                   "   ~  \\\\ //  ~\n"
                   "_- -   | | _- _\n"
                   "  _ -  | |   -_\n"
                   "      // \\\\ \n";
		outfile.close();
	}
}

std::string ShrubberyCreationForm::get_target() const
{
	return(this->_target);
}