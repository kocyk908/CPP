#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::ifstream dbase("data.csv");
	if (!dbase)
		throw(std::string) "cannot open data base";
	std::string line;
	int count = 0;
	std::string value;
	
	while (getline(dbase, line, ','))
	{
		getline(dbase, value);
		this->map[count] = std::make_pair(line, value);
		count++;
	}
	dbase.close();
}

//BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
//{
//	this
//}

BitcoinExchange::~BitcoinExchange()
{

}

//BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &other)
//{
//	return (*this);
//}

const char *BitcoinExchange::CannotOpenFileException::what() const throw()
{
	return ("Error: could not open file.");
}


std::map<int, std::pair<std::string, std::string> > &BitcoinExchange::get_map()
{
	return (this->map);
}

bool BitcoinExchange::isLeap(int year)
{
	return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

bool BitcoinExchange::is_all_nums(std::string date)
{
	int i = 0;
	while (date[i])
	{
		if (!std::isdigit(date[i]))
		{
			return (false);
		}
		i++;
	}
	return (true);
}


bool BitcoinExchange::isValidValue(std::string s)
{
	size_t pos = s.find("|");

	std::string value_str = s.substr(pos+1, s.length()-pos);
	while (!value_str.empty() && isspace(value_str[0]))
		value_str.erase(0, 1);
	if(value_str.empty())
	{
		std::cout << "Error: no value found  			=> '" << s << "'" << std::endl;
		return (false);
	} 
	float value = atof(value_str.c_str());
	if (value < 0)
	{
		std::cout << "Error: not a positive number  		=> " << value << std::endl;
		return (false);
	}
	if (value > 1000)
	{
		std::cout << "Error: value over 1000 			=> " << value << std::endl;
		return (false);
	}
	return (true);
}

bool BitcoinExchange::isValidDate(std::string s)
{
	std::string delimiter = "-";
	size_t pos1 = s.find(delimiter);
	size_t pos2 = s.find(delimiter, pos1 + 1);
	size_t pos_pipe = s.find("|");
	if (pos1 == std::string::npos || pos2 == std::string::npos || pos_pipe == std::string::npos)
		return false;
	std::string year = s.substr(0, pos1);
	std::string month = s.substr(pos1 + 1, pos2 - pos1 - 1);
	std::string day = s.substr(pos2 + 1, pos_pipe - pos2-1);
	// Usuń białe znaki z końca day (kompatybilnie z C++98)
	while (!day.empty() && isspace(day[day.length() - 1]))
		day.erase(day.length() - 1, 1);
	if (year.length() != 4 || month.length() != 2 || day.length() != 2)
		return (false);
	if (!is_all_nums(year) || !is_all_nums(month) || !is_all_nums(day))
		return false;
	int y = atoi(year.c_str());
	int m = atoi(month.c_str());
	int d = atoi(day.c_str());
	if (y <= 0)
		return (false);
	if (m < 1 || m > 12)
		return false;
	if (d < 1 || d > 31)
		return false;
	// Luty
	if (m == 2)
		return isLeap(y) ? (d <= 29) : (d <= 28);
	// Kwiecień, czerwiec, wrzesień, listopad
	if (m == 4 || m == 6 || m == 9 || m == 11)
		return (d <= 30);

	return true;
}

bool BitcoinExchange::isValidInput(std::string s)
{
	if (s.find('|') == std::string::npos)
	{
		std::cout << "Error: bad input 			=> "<< s << "\n";
		return (false);
	}
	if (!isValidDate(s))
	{
		std::cout << "Error: not a valid date 		=> " << s << "\n";
		return (false);
	}
	if (!isValidValue(s))
	{
		return (false);
	}
	return true;
}

void BitcoinExchange::load_file(char *file_name)
{
	std::ifstream file(file_name);
	std::string input;
	std::string date;
	std::string value;
	size_t pos_pipe;
	int header = 0;
	float val_num;
	
	if (!file)
	{
		throw CannotOpenFileException();
	}

	while (getline(file, input))
	{
		if (header == 0)
		{
			header++;
			continue;
		}
		if (input.empty() || !isValidInput(input))
		{
			continue;
		}
		
		pos_pipe = input.find("|");
		date = input.substr(0, pos_pipe);
		value = input.substr(pos_pipe + 1, input.length()-pos_pipe-1);

		val_num = atof(value.c_str());
		std::map<int, std::pair<std::string, std::string> >::const_iterator it = map.begin();
		it++;
	    while (it != map.end() && date > it->second.first)
		{
			it++;
	    }
		it--;
		if (it == map.begin())
		{
			std::cout << "Error: no records before this date 	=> "<< date << "\n";
			continue;
		}
		else
			std::cout << date << "=> " << val_num << " = " << val_num * atof(it->second.first.c_str()) << "\n";
	}
	return ;
}