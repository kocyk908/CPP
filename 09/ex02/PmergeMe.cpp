#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _vct(), _deq()
{

}

PmergeMe::~PmergeMe()
{

}

PmergeMe::PmergeMe(char **args, int count)
{
	for (int i = 0; i < count; i++)
	{
		if (args[i][0] == '\0')
		{
			std::cerr << "Error" << std::endl;
			exit(1);
		}	
		for (int j = 0; args[i][j]; j++)
		{
			if (isdigit(args[i][j]) == false || (int)args[i][0] <= 0)
			{
				std::cerr << "Error" << std::endl;
				exit(1);
			}
		}	
		_vct.push_back(std::atoi(args[i]));
		_deq.push_back(std::atoi(args[i]));
	}
}

PmergeMe::PmergeMe(const PmergeMe& other) : _vct(other._vct), _deq(other._deq)
{
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_vct = other._vct;
		_deq = other._deq;
	}
	return (*this);
}

// Helper functions

void print_vector(std::vector<int>& v)
{
    for (size_t i = 0; i < v.size(); ++i)
        std::cout << v[i] << (i + 1 < v.size() ? ' ' : '\n');
}

void print_deque(std::deque<int>& d)
{
	for (size_t i = 0; i < d.size(); ++i)
		std::cout << d[i] << (i + 1 < d.size() ? ' ' : '\n');
}

std::vector<int> &PmergeMe::get_vct()
{
	return (_vct);
}

std::deque<int> &PmergeMe::get_deq()
{
	return (_deq);
}

time_t	PmergeMe::get_time_microseconds()
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}

void	PmergeMe::mergeSort(void)
{
	std::cout << "Before: 	";
	print_deque(_deq);
	
	clock_t v_start = std::clock();
	merge_insert_vec(_vct);
	clock_t v_end = std::clock();
	double us_v = static_cast<double>(v_end - v_start) * 1e6 /  CLOCKS_PER_SEC;
	
	clock_t d_start = std::clock();
	merge_insert_deq(_deq);
	clock_t d_end = std::clock();
	double us_d = static_cast<double>(d_end - d_start) * 1e6 /  CLOCKS_PER_SEC;
	

	std::cout << "After [vector]: ";
	print_vector(_vct);
	std::cout << "After [deque]:  ";
	print_deque(_deq);

	std::cout << "Time to process a range of " << _vct.size();
	std::cout << " elements with std::vector : " << us_v << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size();
	std::cout << " elements with std::deque  : " << us_d << " us" << std::endl;
}