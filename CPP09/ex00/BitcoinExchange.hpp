#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>

class BitcoinExchange
{
	protected:
		typedef std::map<std::string, std::string>::iterator iterator;
		typedef std::map<std::string, std::string>::const_iterator const_iterator;

	private:
		std::map<std::string, std::string>	rates;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange& operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void	parseLine(const std::string &str, std::string &date, double &quantity);
		double	findPrice(const std::string &date)	const;
};

#endif
