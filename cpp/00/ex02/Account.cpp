/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:20:32 by daypark           #+#    #+#             */
/*   Updated: 2022/01/26 18:20:40 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void){
	time_t timer = time(NULL);
	struct tm* t = localtime(&timer);
	
	std::cout << "[" << std::setw(2) << std::setfill('0') << t->tm_year - 100;
	std::cout << std::setw(2) << std::setfill('0') << t->tm_mon + 1;
	std::cout << std::setw(2) << std::setfill('0') << t->tm_mday << "_";
	std::cout << std::setw(2) << std::setfill('0') << t->tm_hour;
	std::cout << std::setw(2) << std::setfill('0') << t->tm_min;
	std::cout << std::setw(2) << std::setfill('0') << t->tm_sec << "] ";
}

Account::Account(int initial_deposit){
	_displayTimestamp();
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += initial_deposit;
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";created" << std::endl;
}

void Account::displayAccountsInfos(void){
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts;
	std::cout << ";total:" << _totalAmount;
	std::cout << ";deposits:" << _totalNbDeposits;
	std::cout << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::displayStatus(void) const{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit){
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	std::cout << ";deposit:" << deposit;
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << ";amount:" << _amount;
	std::cout << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal){
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	std::cout << ";withdrawal:";
	if (_amount < withdrawal){
		std::cout << "refused" << std::endl;
		return false;
	}
	std::cout << withdrawal;
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout << ";amount:" << _amount;
	std::cout << ";nb_withdrawals" << _nbWithdrawals << std::endl;
	return true;
}

Account::~Account(void){
	_displayTimestamp();
	_nbAccounts--;
	_totalAmount -= _amount;
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";closed"<< std::endl;
}

int Account::checkAmount(void) const{
	return _amount;
}

int Account::getNbAccounts(void){
	return _nbAccounts;
}

int Account::getTotalAmount(void){
	return _totalAmount;
}

int Account::getNbDeposits(void){
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void){
	return _totalNbWithdrawals;
}
