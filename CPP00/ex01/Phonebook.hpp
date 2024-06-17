/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:43:14 by dboire            #+#    #+#             */
/*   Updated: 2024/06/16 14:46:34 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H
#include "Contact.hpp"
#include <iostream>

class Phonebook{

private:
	Contact _contact[8];

public:
	Phonebook(){};
	~Phonebook(){};
	void	Add_info(std::string in, int i);
	void	Search(void);
	void	Show_Contact(int i);

};

#endif