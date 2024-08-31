/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 10:31:20 by dboire            #+#    #+#             */
/*   Updated: 2024/08/31 14:41:28 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Bureaucrat.hpp"

int main()
{
	try 
	{
		Form formA("FormA", 10, 20);
		Bureaucrat john("John", 1);
		std::cout << john << std::endl;
		std::cout << formA << std::endl;
		std::cout << formA.get_signature() << std::endl;
		john.signForm(formA);
		std::cout << formA.get_signature() << std::endl;
		Form HighForm("HighForm", -1, 20);
		john.increment_grade(john.get_grade());
	} 
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	} 
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const Form::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	} 
	catch (const Form::GradeTooLowException& e)
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
		Bureaucrat high("TooHigh", -1);
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