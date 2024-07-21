/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 10:31:18 by dboire            #+#    #+#             */
/*   Updated: 2024/07/21 10:31:18 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat
{
private:
	const std::string   _name;
	int                 _grade;
	Bureaucrat();
public:
	//Canonical
	~Bureaucrat();
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat	&operator=(const Bureaucrat &other);
	
	
	//Exceptions
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
	int get_grade() const;
};



#endif