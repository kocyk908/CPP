#include "Base.hpp"

int	main(void)
{
	A a;
	B b;
	C c;

	std::cout << "Should be A class:\n";
	identify(a);
	identify(&a);
	std::cout << "Should be B class:\n";
	identify(b);
	identify(&b);
	std::cout << "Should be C class:\n";
	identify(c);
	identify(&c);
}