#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

#define DATABASE	"data.csv"

int	main(int argc, char *argv[])
{
	std::ifstream	data_file;
	std::ifstream	infile;
	BitcoinExchange	database;

	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <input file>" << std::endl;
		return (1);
	}
	data_file.open(DATABASE);
	if (!data_file.is_open())
	{
		std::cerr << "Error opening: " << DATABASE << std::endl;
		return (2);
	}
	try
	{
		database = BitcoinExchange(data_file);
		infile.open(argv[1]);
		if (!infile.is_open())
		{
			std::cerr << "Error opening: " << argv[1] << std::endl;
			return (3);
		}
		database.printConversions(infile);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
