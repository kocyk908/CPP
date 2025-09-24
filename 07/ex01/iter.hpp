#ifndef ITER_HPP
# define ITER_HPP

# include <cstdlib>
# include <iostream>

template <typename T, typename F> void iter(T *array, size_t length, F func)
{
	if (!array || length == 0)
		return ;
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

template <typename T> void printArrayElem(const T &elem)
{
	std::cout << elem << std::endl;
}


#endif