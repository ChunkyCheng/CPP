/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:16:45 by jchuah            #+#    #+#             */
/*   Updated: 2026/01/13 16:42:37 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//===Constructor & Destructor===//
Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout	<< "index:"
			 	<< _accountIndex
				<< ";amount:"
				<< _amount
				<< ";created"
				<< std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout	<< "index:"
				<< _accountIndex
				<< ";amount:"
				<< _amount
				<< ";closed"
				<< std::endl;
}

//==============================//
//=======Static functions=======//
int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout	<< "accounts:"
				<< _nbAccounts
				<< ";total:"
				<< _totalAmount
				<< ";deposits:"
				<< _totalNbDeposits
				<< ";withdrawals:"
				<< _totalNbWithdrawals
				<< std::endl;
}

void Account::_displayTimestamp(void)
{
	std::time_t t = std::time(NULL);
	std::tm* tm = std::localtime(&t);

	std::cout	<< "["
				<< (tm->tm_year + 1900)
				<< std::setfill('0') << std::setw(2) << (tm->tm_mon + 1)
				<< std::setw(2) << tm->tm_mday
				<< "_"
				<< std::setw(2) << tm->tm_hour
				<< std::setw(2) << tm->tm_min
				<< std::setw(2) << tm->tm_sec
				<< "] ";
}

//==============================//
//=====Non static functions=====//
void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout	<< "index:"
				<< _accountIndex
				<< ";p_amount:"
				<< _amount - deposit
				<< ";deposit:"
				<< deposit
				<< ";amount:"
				<< _amount
				<< ";nb_deposits"
				<< _nbDeposits
				<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout	<< "index:"
				<< _accountIndex
				<< ";p_amount:"
				<< _amount
				<< ";withdrawal:";
	if (_amount < withdrawal)
	{
		std::cout	<< "refused" << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout	<< withdrawal
				<< ";amount:"
				<< _amount
				<< ";nb_withdrawals:"
				<< _nbWithdrawals
				<< std::endl;
	return (true);
}

int	Account::checkAmount(void) const
{
	return (_amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout	<< "index:"
				<< _accountIndex
				<< ";amount:"
				<< _amount
				<< ";deposits:"
				<< _nbDeposits
				<< ";withdrawals:"
				<< _nbWithdrawals
				<< std::endl;
}
