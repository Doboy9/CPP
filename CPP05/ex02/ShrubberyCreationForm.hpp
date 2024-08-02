/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:28:39 by dboire            #+#    #+#             */
/*   Updated: 2024/07/30 15:28:39 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include"Bureaucrat.hpp"
#include"AForm.hpp"
#include <fstream>
#include <string>

class AForm;
class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
private:
	const std::string _target;
	ShrubberyCreationForm();

public:
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

	void execute(Bureaucrat const &executor) const;

	std::string get_target() const;
};

#endif