/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 10:31:20 by dboire            #+#    #+#             */
/*   Updated: 2024/08/01 17:58:41 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try 
	{
		Bureaucrat john("John", 1);
		std::cout << john << std::endl;
		PresidentialPardonForm form("PPF");
		std::cout << form << std::endl;
		//form.beSigned(john);
		form.execute(john);
	} 
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	} 
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const AForm::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	} 
	catch (const AForm::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const AForm::FormNotSignedException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
	Bureaucrat low("TooLow", 151);
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat jane("Jane", 30);
		Bureaucrat janeCopy(jane);
		Bureaucrat janeAssign = jane;
		std::cout << janeCopy << std::endl;
		std::cout << janeAssign << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}