/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 10:31:18 by dboire            #+#    #+#             */
/*   Updated: 2024/08/01 16:58:44 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <iostream>
#include <exception>

class AForm;

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;
public:
	Bureaucrat();
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
	void signForm(AForm &f);

	void executeForm(AForm const &f) const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);


#endif