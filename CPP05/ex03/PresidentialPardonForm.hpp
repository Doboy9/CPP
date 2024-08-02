/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:28:26 by dboire            #+#    #+#             */
/*   Updated: 2024/07/30 15:28:26 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include"Bureaucrat.hpp"
#include"AForm.hpp"
#include<string>

class AForm;
class Bureaucrat;

class PresidentialPardonForm : public AForm
{
private:
	const std::string _target;
	PresidentialPardonForm();

public:
	virtual ~PresidentialPardonForm();
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

	std::string get_target() const;

	void execute(Bureaucrat const &executor) const;
};


#endif