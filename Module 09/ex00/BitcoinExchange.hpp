#ifndef BITCOINEXCHAGNE_HPP
# define BITCOINEXCHAGNE_HPP

# include <map>
# include <string>
# include <fstream>
# include <stdexcept>

class	BitcoinExchange
{
	public:
		BitcoinExchange(void);
		BitcoinExchange(std::ifstream& infile);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange&	operator=(const BitcoinExchange& other);
		~BitcoinExchange(void);

		double	getExchangeRate(const std::string& date) const;
		void	printConversions(std::ifstream& infile) const;

	protected:
	private:
		std::map<std::string, double>	_database;

		bool	_isValidDate(const std::string& date) const;

	public:
		class	CsvFormatException : public std::exception
		{
			public:
				const char	*what(void) const throw();
		};
};

#endif
