/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:22:03 by dboire            #+#    #+#             */
/*   Updated: 2024/08/01 14:22:03 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "Bureaucrat.hpp"

class Intern : public Bureaucrat
{
private:

public:

	Intern();
	~Intern();
	AForm* makeForm(std::string _name, std::string target);

	AForm *RobotomyRequest(const std::string &target);
	AForm *ShrubberyCreation(const std::string &target);
	AForm *PresidentialPardon(const std::string &target);
};

#endif