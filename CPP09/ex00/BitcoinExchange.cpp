#include "BitcoinExchange.hpp"
#include <fstream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <cerrno>

BitcoinExchange::BitcoinExchange()
{
	// open database
	std::ifstream	dataBase("data.csv");
	if (!dataBase)
		throw std::ios_base::failure("Cannot open data.csv");

	// filling map
	std::string		date;
	std::string		price;
	while (std::getline(dataBase, date, ',') && std::getline(dataBase, price))
		rates[date] = price;
	if (rates.empty())
		throw std::logic_error("Empty data.csv");
	// Drops the header row: "date" sorts after every real date, so it lands last.
	rates.erase(--rates.end());
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) :rates(other.rates) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other) {
		rates = other.rates;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

static	tm getDate(const std::string &date)
{
	std::string yearStr = date.substr(0, 4);
	std::string monthStr = date.substr(5, 2);
	std::string dayStr = date.substr(8, 2);

	int	year = std::atoi(yearStr.c_str());
	int	month = std::atoi(monthStr.c_str());
	int	day = std::atoi(dayStr.c_str());

	struct tm	tmp;
	memset(&tmp, 0, sizeof(tmp));
	tmp.tm_year = year - 1900;
	tmp.tm_mon = month - 1;
	tmp.tm_mday = day;

	mktime(&tmp);

	return (tmp);
}

static std::string	formatDate(const struct tm &date)
{
	std::ostringstream	out;

	// setfill is sticky, setw is not: it has to be repeated on every field
	out << std::setfill('0')
		<< std::setw(4) << date.tm_year + 1900 << '-'
		<< std::setw(2) << date.tm_mon + 1 << '-'
		<< std::setw(2) << date.tm_mday;
	return (out.str());
}

void	BitcoinExchange::parseLine(const std::string &str, std::string &date, double &quantity)
{
	unsigned long	strLen = str.length();

	if (strLen < 14)
		throw std::invalid_argument("Invalid input");

	if (str[4] != '-' || str[7] != '-' || str.substr(10, 3) != " | ")
		throw std::invalid_argument("Invalid format");

	date = str.substr(0, 10);
	struct tm tmpDate = getDate(date);
	if (date < "2009-01-02" || date != formatDate(tmpDate))
		throw std::out_of_range("Invalid date");

	std::string	num = str.substr(13, strLen - 13);
	char		*endptr;
	errno = 0;
	quantity = std::strtod(num.c_str(), &endptr);
	if (*endptr != '\0' || errno == ERANGE)
		throw std::invalid_argument("Invalid number");
	if (quantity < 0)
		throw std::out_of_range("Not positive number");
	if (quantity > 1000)
		throw std::out_of_range("Too large number");
}

double	BitcoinExchange::findPrice(const std::string &date)	const
{
	// the map is sorted by date: upper_bound lands just past it, so one step back is the closest earlier one
	const_iterator	it = rates.upper_bound(date);

	if (it == rates.begin())
		throw std::out_of_range("No earlier date in the database");
	--it;
	return (std::atof(it->second.c_str()));
}
