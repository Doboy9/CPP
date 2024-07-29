/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 10:31:18 by dboire            #+#    #+#             */
/*   Updated: 2024/07/29 22:56:51 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "Form.hpp"
#include <iostream>
#include <exception>

class Form;

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;
	Bureaucrat();
public:
	//Canonical
	~Bureaucrat();
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat	&operator=(const Bureaucrat &other);
	
	
	//Exceptions class
	class GradeTooHighException : public std::exception
	{
	public :
		const char *what() const throw();
	};
	
	class GradeTooLowException : public std::exception
	{
	public :
		const char *what() const throw();
	};

	//Increment/Decrement/Validate
	void valid_grade(int grade) const;
	void decrement_grade(int grade);
	void increment_grade(int grade);
	

	//Getters
	const std::string &get_name() const;
	int get_grade() const;
	void signForm(Form &f);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);


#endif