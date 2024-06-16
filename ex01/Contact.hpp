/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 08:14:36 by dboire            #+#    #+#             */
/*   Updated: 2024/06/16 09:22:35 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H
#include <string>

class Contact
{

private :

	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;

public :

	Contact(){};
	~Contact(){};

void setFirstName(std::string str);
void setLastName(std::string str);
void setNickname(std::string str);
void setPhoneNumber(std::string str);
void setDarkestSecret(std::string str);

std::string getFirstName(void);
std::string getLastName(void);
std::string getNickname(void);
std::string getPhoneNumber(void);
std::string getDarkestSecret(void);

};

# endif