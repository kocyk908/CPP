#include "RPN.hpp"


RPN::RPN()
{

}

RPN::~RPN()
{

}

//RPN::RPN(const RPN &other)
//{
//	*this = other;
//}

//RPN	&RPN::operator=(const RPN &other)
//{
//	if (this != &other)
//	{
//		this->map = other.map;
//	}
//	return (*this);
//}

const char *RPN::NotEnoughValuesException::what() const throw()
{
	return ("Error: not enough values in the stack");
}


void RPN::load_expression(std::string expression)
{
	std::stack<int> st;
	int a;
	int b;

	for (size_t i = 0; i < expression.length(); i++)
	{
		if (isdigit(expression[i]))
			st.push(expression[i] - '0');
		else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
		{
			if (st.size() < 2)
			{
				throw NotEnoughValuesException();
			}
			b = st.top();
			st.pop();
			a = st.top();
			st.pop();

			std::cout << "Applying operator " << expression[i] << " on " << a << " and " << b << std::endl;
			
			if (expression[i] == '+')
			{
				st.push(a + b);
			}
			else if (expression[i] == '-')
			{
				st.push(a - b);
			}
			else if (expression[i] == '*')
			{
				st.push(a * b);
			}
			else if (expression[i] == '/')
			{
				if (b == 0)
				{
					throw std::runtime_error("Error: devided by 0");
				}
				st.push(a / b);
			}
		}
		else if (!isspace(expression[i]))
		{
			throw std::runtime_error("Error: invalid character");
		}
	}
	if (st.size() != 1)
	{
		throw std::runtime_error("Error: too many values in the stack");
	}
	std::cout << st.top() << std::endl;
}