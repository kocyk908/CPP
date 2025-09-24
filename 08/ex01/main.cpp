#include "Span.hpp"
#include <cstdlib>

int main()
{
	try {
		Span sp(8);
		Span x(2);
		x.addNumber(1);
		x.addNumber(-1);
		std::cout << "longest span in x: " << x.longestSpan() << std::endl;

		int data[] = {-5, 12, 7, 3};
		int count = sizeof(data) / sizeof(data[0]);
		std::vector<int> nums(data, data + count);

		sp.addNumber(nums.begin(), nums.end());
		sp.addNumber(900);
		sp.addNumber(-10);
		sp.addNumber(898);
		std::cout << "shortest span in sp: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span: in sp: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
}