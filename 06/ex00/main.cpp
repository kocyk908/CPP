#include "conversion.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Wrong argument count" << std::endl;
		return (0);
	}
	std::string scalar(av[1]);
	Conv::convert(scalar);
	return (0);
}