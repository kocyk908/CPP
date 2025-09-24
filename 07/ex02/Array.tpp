#include "Array.hpp"

template <typename T>
Array<T>::Array() : _data(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	if (n > 0)
	{
		_data = new T[_size]();
	}
	else
	{
		_data = NULL;
	}
}


template <typename T>
Array<T>::Array(const Array &src) : _size(src._size)
{
	if (_size > 0)
	{
		_data = new T[_size]();
	}
	else
	{
		_data = NULL;
	}
	for (unsigned int i = 0; i < _size; i++)
	{
		_data[i] = src._data[i];
	}
}

template <typename T>
Array<T>::~Array()
{
	if (_data)
		delete[] _data;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &src)
{
	if (this == &src)
		return (*this);
	
	if (_data != NULL)
	{
		delete [] _data;
	}

	_size = src._size;
	if (_size == 0 || src._data == NULL)
	{
		_data = NULL;
		return (*this);
	}
	_data = new T[_size];
	if (_data)
	{
		for (unsigned int i = 0; i < _size; i++)
			_data[i] = src._data[i];
	}	
	return (*this);
}

template <typename T>
T&	Array<T>::operator[](size_t index)
{
	if (index >= _size)
		throw std::exception();
	return (_data[index]);
}

template <typename T>
const T&	Array<T>::operator[](size_t index) const
{
	if (index >= _size)
		throw std::exception();
	return (_data[index]);
}

template <typename T>
size_t	Array<T>::size() const
{
	return (_size);
}