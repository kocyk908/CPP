#include "BitcoinExchange.hpp"

int main(int ac, char** av)
{
	(void)ac;

	BitcoinExchange bitcoin;

	bitcoin.load_file(av[1]);

	return (0);
}