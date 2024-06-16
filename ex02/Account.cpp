/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:34:20 by dboire            #+#    #+#             */
/*   Updated: 2024/06/16 22:03:01 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
int Account::_totalAmount = 0;

void	Account::_displayTimestamp( void )
{
	std::time_t time = std::time(NULL);
	
	std::cout << "[" 
	<< 1900 + std::localtime(&time)->tm_year 
	<< std::localtime(&time)->tm_mon 
	<< std::localtime(&time)->tm_mday
	<< "-" 
	<< std::localtime(&time)->tm_hour
	<< std::localtime(&time)->tm_min
	<< std::localtime(&time)->tm_sec
	<< "] ";
}
Account::Account(int initial_deposit)
{
	_amount = initial_deposit;
	_totalAmount += _amount;
	_accountIndex = _nbAccounts;
	_displayTimestamp();
	std::cout << "index:" << getNbAccounts() 
	<< ";amount:" << _amount
	<< ";created" << std::endl;
	_nbAccounts++;
}
Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	<< ";amount:" << _amount
	<< ";closed" << std::endl;
	_totalAmount -= _amount;
}


int		Account::getNbAccounts(void){return(_nbAccounts);}
int		Account::getTotalAmount(void){return(_totalAmount);}
int		Account::getNbDeposits(void){return(_totalNbDeposits);}
int		Account::getNbWithdrawals(void){return (_totalNbWithdrawals);}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	<< ";p_amount:" << _amount
	<< ";withdrawal:";
	if(withdrawal > _amount)
		std::cout << "refused" << std::endl;
	else
	{
		_nbWithdrawals++;
		_amount = _amount - withdrawal;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		std::cout << withdrawal
		<< ";amount:" << _amount
		<< ";nb_withdrawals:" << _nbWithdrawals
		<< std::endl;
	}
	return(1);
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	std::cout << "index:" << _accountIndex
	<< ";p_amount:" << _amount
	<< ";deposit:" << deposit
	<< ";amount:" << _amount + deposit
	<< ";nb_deposits:" << _nbDeposits
	<< std::endl;
	_amount = _amount + deposit;
}


void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	<< ";amount:" << _amount
	<< ";deposits:" << _nbDeposits
	<< ";withdrawals:" << _nbWithdrawals
	<< std::endl;
}

void Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() 
	<< ";total:" << getTotalAmount() 
	<< ";deposits:" << getNbDeposits() 
	<< ";withdrawals:" << getNbWithdrawals() 
	<< std::endl;
}