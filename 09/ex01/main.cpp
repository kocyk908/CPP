#include "RPN.hpp"

int main(int ac, char** av)
{
	(void)ac;
	RPN rpn;

	try
	{
		rpn.load_expression(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}