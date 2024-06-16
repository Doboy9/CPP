/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:45:20 by dboire            #+#    #+#             */
/*   Updated: 2024/06/16 08:59:51 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

void Contact::setFirstName(std::string str){_first_name = str;}
void Contact::setLastName(std::string str){_last_name = str;}
void Contact::setNickname(std::string str){_nickname = str;}
void Contact::setPhoneNumber(std::string str){_phone_number = str;}
void Contact::setDarkestSecret(std::string str){_darkest_secret = str;}

std::string Contact::getFirstName(void){return _first_name;}
std::string Contact::getLastName(void){return _last_name;}
std::string Contact::getNickname(void){return _nickname;}
std::string Contact::getPhoneNumber(void){return _phone_number;}
std::string Contact::getDarkestSecret(void){return _darkest_secret;}