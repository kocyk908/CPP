#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <ctime>
# include <cstdlib>

class Base {

    public:
		virtual ~Base() {};
};

class A : public Base {

};

class B : public Base {

};

class C : public Base {

};

Base * generate(void)
{
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
		std::cout << "Identified as class A (pointer)\n";
    else if (dynamic_cast<B*>(p))
		std::cout << "Identified as class B (pointer)\n";
    else if (dynamic_cast<C*>(p))
		std::cout << "Identified as class C (pointer)\n";
	else
		std::cout << "Could not identify object\n";
}

void	identify(Base& p)
{
	A*	a;
	B*	b;
	C*	c;

	if ((a = dynamic_cast<A*>(&p)))
		std::cout << "Identified as class A (reference)\n";
	else if ((b = dynamic_cast<B*>(&p)))
		std::cout << "Identified as class B (reference)\n";
	else if ((c = dynamic_cast<C*>(&p)))
		std::cout << "Identified as class C (reference)\n";
	else
		std::cout << "Could not identiy object\n";
}

#endif