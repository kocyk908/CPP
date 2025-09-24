#include "Span.hpp"

Span::Span() : _array()
{
	std::cout << "Default Span is created" << std::endl;
	std::cout << "Capacity: " << _array.capacity() << std::endl;
	std::cout << "Size: " << _array.size() << std::endl;
}
Span::Span(unsigned int N) : _array()
{
	std::cout << "Span with N size is created" << std::endl;
	_array.reserve(N);
	std::cout << "Capacity: " << _array.capacity() << std::endl;
	std::cout << "Size: " << _array.size() << std::endl;
}
Span::Span(const Span& other) : _array(other._array)
{
	std::cout << "Span copy is created" << std::endl;
	_array.reserve(other._array.capacity());
	std::cout << "Capacity: " << _array.capacity() << std::endl;
	std::cout << "Size: " << _array.size() << std::endl;
}

Span::~Span(){};

Span	&Span::operator=(const Span& other)
{
    if (this != &other)
	{
        _array = other._array;
    }
    return (*this);
}

void Span::addNumber(int Num)
{
	if (_array.capacity() > _array.size())
		_array.push_back(Num);
	else
		throw std::exception();
} 

void Span::addNumber(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end)
{
	for (std::vector<int>::const_iterator it = begin; it != end; it++)
	{
		if (_array.size() < _array.capacity())
		{
			_array.push_back(*it);
		}
		else
		{
			throw std::exception();
		}
	}
}

int Span::longestSpan() const
{
	if (_array.size() < 2)
	{
		throw std::exception();
	}

	std::vector<int> tmp = _array;
	std::sort(tmp.begin(), tmp.end());
	return (tmp[_array.size()-1] - tmp[0]);
}

int Span::shortestSpan() const
{
	if (_array.size() < 2)
	{
		throw std::exception();
	}

	std::vector<int> tmp = _array;
	
	std::sort(tmp.begin(), tmp.end());
	int min = tmp[1] - tmp[0];
	for (std::vector<int>::size_type i = 2; i < tmp.size(); i++)
	{
		if (tmp[i] - tmp[i-1] < min)
		{
			min = tmp[i] - tmp[i-1];
		}
	}
	return (min);
}

void Span::print_vector()
{
	std::cout << "Vector elements: ";
	for (std::vector<int>::size_type i = 0; i < _array.size(); i++)
	{
		std::cout << _array[i] << " ";
	}
	std::cout << std::endl;
}