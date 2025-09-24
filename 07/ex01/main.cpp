#include "iter.hpp"

void	multiply_by_two(int& elem)
{
	elem *= 2;
}

int	main(void)
{	
	std::cout << "------------Int------------\n";
	int intArr[] = {1, 2, 3, 4, 5};
	std::size_t size = sizeof(intArr) / sizeof(intArr[0]);

	::iter(intArr, size, printArrayElem<int>);
	std::cout << "After *2:\n";
	::iter(intArr, size, multiply_by_two);
	::iter(intArr, size, printArrayElem<int>);

	std::cout << "\n------------Char------------\n";
	char charArr[] = {'x', '*', '!', '+', ' '};
	size = sizeof(charArr) / sizeof(charArr[0]);
	::iter(charArr, size, printArrayElem<char>);

	std::cout << "\n------------Float------------\n";
	float	floarArr[] = {1.0f, 11111.1111f, 0.5f, 15.010f, 12.f};
	size = sizeof(floarArr) / sizeof(floarArr[0]);
	::iter(floarArr, size, printArrayElem<float>);

	std::cout << "\n------------String------------\n";
	std::string strArr[] = {"hello", "world", "!"};
	size = sizeof(strArr) / sizeof(strArr[0]);
	::iter(strArr, size, printArrayElem<std::string>);
}/