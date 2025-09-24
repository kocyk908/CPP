#include "easyfind.hpp"
#include <vector>
#include <algorithm>

int	main(void)
{
	int	arr[] = {10, 20, 5, 23, 42, 15};
	int	n;

	n = sizeof(arr) / sizeof(arr[0]);
	std::vector<int> vect(arr, arr + n);

	try
	{
		easyfind(vect, -42);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	easyfind(vect, 42);
}
