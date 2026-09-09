#include <sys/time.h>
#include <iostream>
#include <iomanip>
#include "Account.hpp"


int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account()
{}

Account::~Account()
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "closed" << std::endl;
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "created" << std::endl;
}

void	Account::_displayTimestamp()
{
	struct timeval	tv;
	struct tm *timeinfo;

	gettimeofday(&tv, NULL);
	timeinfo = localtime(&tv.tv_sec);

	std::cout << "["
				<< (timeinfo->tm_year + 1900)
				<< std::setfill('0') << std::setw(2)
				<< (timeinfo->tm_mon + 1)
				<< std::setfill('0') << std::setw(2)
				<< timeinfo->tm_mday
				<< "_"
				<< std::setfill('0') << std::setw(2)
				<< timeinfo->tm_hour
				<< std::setfill('0') << std::setw(2)
				<< timeinfo->tm_min
				<< std::setfill('0') << std::setw(2)
				<< timeinfo->tm_sec
				<< "]";
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts << ";"
				<< "total:" << _totalAmount << ";"
				<< "deposits:" << _totalNbDeposits << ";"
				<< "withdrawals:" << _totalNbWithdrawals
				<< std::endl;
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "deposits:" << _nbDeposits << ";"
				<< "withdrawals:" << _nbWithdrawals
				<< std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";"
				<< "p_amount:" << _amount << ";"
				<< "deposit:" << deposit << ";";
	_nbDeposits += 1;
	_totalNbDeposits += 1;
	_amount += deposit;
	_totalAmount += deposit;
	std::cout << "amount:" << _amount << ";"
				<< "nb_deposits:" << _nbDeposits
				<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";"
				<< "p_amount:" << _amount << ";";

	if (withdrawal > _amount) {
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	_nbWithdrawals += 1;
	_totalNbWithdrawals += 1;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	std::cout << "withdrawal:" << withdrawal << ";"
				<< "amount:" << _amount << ";"
				<< "nb_withdrawals:" << _nbWithdrawals
				<< std::endl;
	return (true);
}
