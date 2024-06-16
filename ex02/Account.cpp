/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:34:20 by dboire            #+#    #+#             */
/*   Updated: 2024/06/16 18:41:17 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
int Account::_totalAmount = 0;

Account::Account(int initial_deposit)
{
	Account::_totalAmount = initial_deposit;
}
Account::~Account(){}


int  Account::getNbAccounts(void){return(_nbAccounts);}
int	Account::getTotalAmount(void){return(_totalAmount);}
int	Account::getNbDeposits(void){return(_totalNbDeposits);}
int	Account::getNbWithdrawals(void){return (_totalNbWithdrawals);}
bool	Account::makeWithdrawal( int withdrawal ){return (_totalAmount -= withdrawal);}

void	Account::makeDeposit( int deposit ){_amount = deposit;}


void	Account::displayStatus( void ) const
{
	std::cout << getTotalAmount() << std::endl;
}

void Account::displayAccountsInfos( void )
{
	std::cout << getTotalAmount() << std::endl;
}