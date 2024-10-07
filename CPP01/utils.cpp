#include "pbook.hpp"

std::string add_input(std::string str)
{
	int i = 0;
	std::getline(std::cin, str);
	while (str.empty())
	{
		if (i == 0)
		{
			std::cout << "You can't leave blank field. Please try again: \n";
			i++;
		}
		std::getline(std::cin, str);
	}
	return (str);

}