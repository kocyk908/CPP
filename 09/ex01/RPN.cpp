#include "RPN.hpp"

RPN::RPN()
{

}

RPN::~RPN()
{

}

RPN::RPN(RPN const &other)
{
	if (this != &other)
		*this = other;
}

RPN &RPN::operator=(RPN const &other)
{
	if (this != &other)
		this->st = other.st;
	return (*this);
}

const char *RPN::NotEnoughValuesException::what() const throw()
{
	return ("Error: not enough values in the stack");
}

const char *RPN::TooManyValuesException::what() const throw()
{
	return ("Error: too many values in the stack");
}

const char *RPN::DevideByZeroException::what() const throw()
{
	return ("Error: devided by 0");
}

const char *RPN::InvalidCharacterException::what() const throw()
{
	return ("Error: invalid character in the expression");
}

const char *RPN::WrongArgumentCountException::what() const throw()
{
	return ("Error: wrong number of arguments");
}

const char *RPN::MoreThanOneDigitNumberException::what() const throw()
{
	return ("Error: more than one digit number in the expression");
}

void RPN::load_expression(char** av)
{
	int a;
	int b;

	if (av[2])
	{
		throw WrongArgumentCountException();
	}

	std::string expression = av[1];

	for (size_t i = 0; i < expression.length(); i++)
	{
		if (isdigit(expression[i]) && isdigit(expression[i + 1]))
		{
			throw MoreThanOneDigitNumberException();
		}
		if (isdigit(expression[i]))
			this->st.push(expression[i] - '0');
		else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
		{
			if (this->st.size() < 2)
			{
				throw NotEnoughValuesException();
			}
			b = this->st.top();
			this->st.pop();
			a = this->st.top();
			this->st.pop();

			// std::cout << "Applying operator " << expression[i] << " on " << a << " and " << b << std::endl;
			
			if (expression[i] == '+')
			{
				this->st.push(a + b);
			}
			else if (expression[i] == '-')
			{
				this->st.push(a - b);
			}
			else if (expression[i] == '*')
			{
				this->st.push(a * b);
			}
			else if (expression[i] == '/')
			{
				if (b == 0)
				{
					throw DevideByZeroException();
				}
				this->st.push(a / b);
			}
		}
		else if (!isspace(expression[i]))
		{
			throw InvalidCharacterException();
		}
	}
	if (this->st.size() != 1)
	{
		throw TooManyValuesException();
	}
	std::cout << this->st.top() << std::endl;
}