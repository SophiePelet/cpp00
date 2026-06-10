/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 10:54:05 by sopelet           #+#    #+#             */
/*   Updated: 2026/06/10 15:05:39 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

#define CYAN	"\033[36m"
#define RESET	"\033[0m"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/*
	Constructor function:
	Initializes a new account, updates global bank stats, and logs creation
*/
Account::Account(int initial_deposit) {
	_totalAmount += initial_deposit;
	_amount = initial_deposit;
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_displayTimestamp();
	std::cout << "index:" << CYAN << _accountIndex << RESET << ";amount:" << CYAN
	<< initial_deposit << RESET << ";created" << std::endl;
}

/*
	Logs the final state (index and remaining balance) with a timestamp 
	before the account object is destroyed.
*/
Account::~Account(){
	_displayTimestamp();
	std::cout << "index:" << CYAN << _accountIndex << RESET << ";amount:" << CYAN << _amount << RESET
				<< ";closed" << std::endl;
}

int	Account::getNbAccounts(){
	return (_nbAccounts);
}

int	Account::getTotalAmount() {
	return (_totalAmount);
}

int	Account::getNbDeposits() {
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals() {
	return (_totalNbWithdrawals);
}

int	Account::checkAmount(void) const {
	return (_amount);
}

/*
	Display a timestamped summary for all accounts
*/
void	Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout << "account:" << CYAN << _nbAccounts << RESET << ";total:" << CYAN << _totalAmount << RESET << ";deposits:"
				<< CYAN << _totalNbDeposits << RESET << ";withdrawals:" << CYAN << _totalNbWithdrawals << RESET << std::endl;
}

/*
	Updates the account balance with `deposit`
	Increments `_totalNbDeposits`
*/
void	Account::makeDeposit(int deposit) {
	int	p_amount = _amount;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	
	_displayTimestamp();
	std::cout << "index:" << CYAN << _accountIndex << RESET << ":p_amount:" << CYAN << p_amount << RESET << ";deposit:" << CYAN << deposit
				<< RESET << ";amount:" << CYAN << _amount << RESET << ";nb_deposit:" << CYAN << _nbDeposits << RESET << std::endl;
}

/*
	Updates the account balance with `withdrawal` if there is enough money in the account
	If not enough money -> withdrawal refused and the function returns `false`
	else, it returns `true`
	Increments `_totalNbWithdrawals` if the withdrawal is successful
*/
bool	Account::makeWithdrawal(int withdrawal) {
	if (_amount < withdrawal) {
		_displayTimestamp();
		std::cout << "index:" << CYAN << _accountIndex << RESET << ";p_amount:" << CYAN << _amount << RESET << ";withdrawal:"
				<< CYAN << withdrawal << RESET << ";refused" << std::endl;
		return (false);
	}
	int    p_amount = _amount;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;

	_displayTimestamp();
	std::cout << "index:" << CYAN << _accountIndex << RESET << ";p_amount:" << CYAN << p_amount << RESET << ";withdrawal:" << CYAN 
				<< withdrawal << RESET << ";amount:" << CYAN << _amount << RESET << ";nb_withdrawals:" << CYAN << _nbWithdrawals << RESET << std::endl;
	return (true);
}

/*
	Displays the current time in a [YYYYMMDD_HHMMSS] format
	- `time()` fetches the current time in seconds
	- `localtime()` translates that time into a human readable format based on your local time zone
	(breaks down the giant nb given by `time()` into a `tm` structure)
*/
void	Account::_displayTimestamp() {
	time_t	now;
	struct	tm *date;
	
	time(&now);
	date = localtime(&now);

	int		year = date->tm_year + 1900;
	int		month = date->tm_mon + 1;
	int		day = date->tm_mday;
	int		hour = date->tm_hour;
	int		minute = date->tm_min;
	int		second = date->tm_sec;
	
	std::cout << "[" << year
		<< std::setw(2) << std::setfill('0') << month
		<< std::setw(2) << day << "_"
		<< std::setw(2) << hour << std::setw(2) << minute << std::setw(2) << second << "] ";
}

/*
	Displays the index, account balance, nb of deposits and nb of withdrawals for each account
*/
void	Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" << CYAN << _accountIndex << RESET << ";amount:" << CYAN << _amount << RESET << ";deposits:"
				<< CYAN << _nbDeposits << RESET << ";withdrawals:" << CYAN << _nbWithdrawals << RESET << std::endl;
}