#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <math.h>

class BitcoinExchange{

	private:
		std::map<int, std::pair<std::string, std::string> > map;

	public:
		BitcoinExchange();
		//BitcoinExchange(const BitcoinExchange &other);
		~BitcoinExchange();
		//BitcoinExchange	&operator=(const BitcoinExchange &other);

		std::map<int, std::pair<std::string, std::string> >& get_map();

		void load_file(char *file_name);

		bool isValidInput(std::string s);
		bool isValidDate(std::string s);
		bool isValidValue(std::string s);
		bool is_all_nums(std::string date);
		bool isLeap(int year);

		class CannotOpenFileException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};
#endif