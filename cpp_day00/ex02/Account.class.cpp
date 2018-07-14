// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Account.class.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/02 15:49:12 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/02 15:49:13 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Account.class.hpp"
#include <iostream>
#include <ctime>

	int	Account::_nbAccounts = 0;
	int	Account::_totalAmount = 0;
	int	Account::_totalNbDeposits = 0;
	int	Account::_totalNbWithdrawals = 0;

	Account::Account( void ) {
		return ;
	}

	Account::Account( int initial_deposit ) {
		_displayTimestamp();
		std::cout << "index:" << _nbAccounts << ";amount:" << initial_deposit << ";created" << std::endl;
		_accountIndex = _nbAccounts;
		_nbAccounts++;
		_totalAmount += initial_deposit;
		_amount = initial_deposit;
		_nbDeposits = 0;
		_nbWithdrawals = 0;
		return ;
	}
	
	Account::~Account(void) {
		_nbAccounts--;
		_displayTimestamp();
		std::cout << "index:" << _nbAccounts << ";amount:" << _amount << ";closed" << std::endl;
		return ;
	}

/*
*** place money to deposits
*/

	void	Account::makeDeposit( int deposit ) {
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
		_totalAmount += deposit;
		_totalNbDeposits++;
		_amount +=deposit;
		_nbDeposits++;
		std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
	}

/*
*** take money from check
*/
	bool	Account::makeWithdrawal( int withdrawal ) {

		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
		if (_amount < withdrawal)
		{
			std::cout << "refused" << std::endl;
			return (false);
		}
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		_nbWithdrawals++;
		_amount -= withdrawal;
		std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return (true);
	}

	int		Account::checkAmount( void ) const {
		return (this->_amount);
	}

	void	Account::displayStatus( void ) const {
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits
				<< ";withdrawal:" << _nbWithdrawals << std::endl;
	}

	int	Account::getNbAccounts( void ) {
		return (_nbAccounts);
	}

	int	Account::getTotalAmount( void ) {
		return (_totalAmount);
	}

	int	Account::getNbDeposits( void ) {
		return (_totalNbDeposits);
	}

	int	Account::getNbWithdrawals( void ) {
		return (_totalNbWithdrawals);
	}

	void	Account::displayAccountsInfos( void ) {
		_displayTimestamp();
		std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits <<
				";withdrawals:" << _totalNbWithdrawals << std::endl;
	}

	void	Account::_displayTimestamp( void ) {
		struct tm * timeinfo;
		char buffer [80];
		time_t timer = time(&timer);
		timeinfo = localtime (&timer);
		strftime (buffer, 80, "%Y%m%d_%H%M%S", timeinfo);
		std::cout << "[" << buffer << "] ";
	}
