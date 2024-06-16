/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:45:20 by dboire            #+#    #+#             */
/*   Updated: 2024/06/14 18:45:20 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

void Contact::takeFirstName(std::string str){first_name = str;}
void Contact::takeLastName(std::string str){last_name = str;}
void Contact::takeNickname(std::string str){nickname = str;}
void Contact::takePhoneNumber(std::string str){phone_number = str;}
void Contact::takeDarkestSecret(std::string str){darkest_secret = str;}

std::string Contact::printFirstName(void){return first_name;}
std::string Contact::printLastName(void){return last_name;}
std::string Contact::printNickname(void){return nickname;}
std::string Contact::printPhoneNumber(void){return phone_number;}
std::string Contact::printDarkestSecret(void){return darkest_secret;}