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

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"
#include<iostream>
#include<string>

class Bureaucrat;
class AForm;

class   AForm
{
private:
	const std::string	_name;
	bool				_signed;
	const int			_grade_signing;
	const int			_grade_executing;
	AForm();

public:
    
	//Canonical forms
	~AForm();
	AForm(const std::string &name, int grade_signing, int grade_executing);
	AForm(const AForm &other);
	AForm	&operator=(const AForm &other);

	virtual void execute(Bureaucrat const & executor) const = 0;

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

	class FormNotSignedException : public std::exception
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

std::ostream& operator<<(std::ostream& os, const AForm& b);

#endif