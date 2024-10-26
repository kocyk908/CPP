#include <iostream>
#include <string>

int main()
{
	std::string hello = "HI THIS IS BRAIN";

	std::string *ptr = &hello;
	std::string &ref = hello;

	std::cout << "Memory address of the string: " << &hello << std::endl;
	std::cout << "Memory address held by pointer: " << ptr << std::endl;
	std::cout << "Memory address held by reference: " << &ref << std::endl;

	std::cout << "Value of the string: " << hello << std::endl;
	std::cout << "Value pointed to by pointer: " << *ptr << std::endl;
	std::cout << "Value pointed to by reference: " << ref << std::endl;

	return (0);
}