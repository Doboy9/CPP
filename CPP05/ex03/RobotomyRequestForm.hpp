/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:28:36 by dboire            #+#    #+#             */
/*   Updated: 2024/07/30 15:28:36 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include"Bureaucrat.hpp"
#include"AForm.hpp"
#include<string>

class AForm;
class Bureaucrat;

class RobotomyRequestForm : public AForm
{
private:
	const std::string _target;
	RobotomyRequestForm();

public:
	virtual ~RobotomyRequestForm();
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

	void execute(Bureaucrat const &executor) const;

	std::string get_target() const;
};


#endif