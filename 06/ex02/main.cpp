#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	srand(time(NULL));
	int i = std::rand() % 3;
	if (i == 0)
	{
		return (new A());
	}
	else if (i == 1)
	{
		return (new B());
	}
	else
	{
		return (new C());
	}
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
		std::cout << "	Identified as class A (pointer)\n";
    else if (dynamic_cast<B*>(p))
		std::cout << "	Identified as class B (pointer)\n";
    else if (dynamic_cast<C*>(p))
		std::cout << "	Identified as class C (pointer)\n";
	else
		std::cout << "	Could not identify object\n";
}

void	identify(Base& p)
{
	A*	a;
	B*	b;
	C*	c;

	if ((a = dynamic_cast<A*>(&p)))
		std::cout << "	Identified as class A (reference)\n";
	else if ((b = dynamic_cast<B*>(&p)))
		std::cout << "	Identified as class B (reference)\n";
	else if ((c = dynamic_cast<C*>(&p)))
		std::cout << "	Identified as class C (reference)\n";
	else
		std::cout << "	Could not identiy object\n";
}

int	main(void)
{
	A a;
	B b;
	C c;

	Base *	ptr = generate();

	
	std::cout << "Should be A class:\n";
	identify(a);
	identify(&a);
	std::cout << "Should be B class:\n";
	identify(b);
	identify(&b);
	std::cout << "Should be C class:\n";
	identify(c);
	identify(&c);
	std::cout << "Random class:\n";
	identify(ptr);
	identify(*ptr);
	
	delete ptr;
}
