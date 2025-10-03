#include "MutantStack.hpp"
#include "MutantStack.tpp"

int main()
{
	std::cout << "Subject main: \n";

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "\nAdditional tests MutantStack:\n";

	MutantStack<int> empty_stack;
	std::cout << "Empty stack size: " << empty_stack.size() << std::endl;
	if (empty_stack.begin() == empty_stack.end())
		std::cout << "Empty stack has no elements (begin == end)" << std::endl;

	MutantStack<int> copy_stack = mstack;
	std::cout << "Copy stack size (mstack copy): " << copy_stack.size() << " Original stack size: " << mstack.size() << std::endl;
	std::cout << "Copy stack elements: ";
	MutantStack<int>::iterator it_cpy = mstack.begin();
	MutantStack<int>::iterator ite_cpy = mstack.end();
	while (it_cpy != ite_cpy)
	{
		std::cout << *it_cpy << ", " ;
		++it_cpy;
	}
	std::cout << std::endl;

	MutantStack<std::string> string_stack;
	string_stack.push("hello");
	string_stack.push("world");
	string_stack.push("42");
	std::cout << "String stack: ";
	MutantStack<std::string>::iterator it_str = string_stack.begin();
	MutantStack<std::string>::iterator ite_str = string_stack.end();
	while (it_str != ite_str)
	{
		std::cout << *it_str << ", ";
		++it_str;
	}
	std::cout << std::endl;

	return (0);
}
