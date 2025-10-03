#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

# include "MutantStack.hpp"

template <typename T>
typename std::stack<T>::container_type::iterator	MutantStack<T>::begin()
{
	return (this->c.begin());
}

template <typename T>
typename std::stack<T>::container_type::iterator	MutantStack<T>::end()
{
	return (this->c.end());
}

template <typename T>
typename std::stack<T>::container_type::const_iterator	MutantStack<T>::begin() const
{
	return (this->c.begin());
}

template <typename T>
typename std::stack<T>::container_type::const_iterator	MutantStack<T>::end() const
{
	return (this->c.end());
}

#endif
