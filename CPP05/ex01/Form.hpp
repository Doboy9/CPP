/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:00:38 by dboire            #+#    #+#             */
/*   Updated: 2024/07/29 15:00:38 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include<iostream>

class Bureaucrat;

class   Form
{
private:
	const std::string	_name;
	bool				_signed;
	const int			_grade_signing;
	const int			_grade_executing;
	Form();

public:
    
	//Canonical forms
	~Form();
	Form(const std::string &name, int grade_signing, int grade_executing);
	Form(const Form &other);
	Form	&operator=(const Form &other);

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


	//Getters
	const std::string &get_name() const;
	int get_grade_signing() const;
	int get_grade_executing() const;
	bool get_signature() const;

	void valid_grade(int grade) const;

	void beSigned(Bureaucrat &b);


};

std::ostream& operator<<(std::ostream& os, const Form& b);

#endif