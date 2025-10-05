#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _vct(), _dqe()
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
			if (!isdigit(args[i][j]))
			{
				std::cerr << "Error" << std::endl;
				exit(1);
			}
		_vct.push_back(std::atoi(args[i]));
		_dqe.push_back(std::atoi(args[i]));
	}
}

PmergeMe::PmergeMe(const PmergeMe& other) : _vct(other._vct), _dqe(other._dqe)
{
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_vct = other._vct;
		_dqe = other._dqe;
	}
	return (*this);
}

// Mergesort for vector
void PmergeMe::merge_vct(std::vector<int> &vct, std::vector<int> rvct, std::vector<int> lvct)
{
	std::vector<int>::iterator itl = lvct.begin();
	std::vector<int>::iterator itr = rvct.begin();
	
	int i = 0;
	while (itl != lvct.end() && itr != rvct.end())
	{
		if (*itl <= *itr)
		{
			vct[i] = *itl;
			i++;
			itl++;
		}
		else
		{
			vct[i] = *itr;
			i++;
			itr++;
		}
	}
	while (itl != lvct.end())
	{
		vct[i] = *itl;
		i++;
		itl++;
	}
	while (itr != rvct.end())
	{
		vct[i] = *itr;
		i++;
		itr++;
	}
}

void PmergeMe::mergeSort_vct(std::vector<int> &vct)
{
	int len = vct.size();
	if (len <= 1)
	{
		return ;
	}
	int middle = len / 2;
	std::vector<int> lvct;
	lvct.reserve(middle);
	std::vector<int> rvct;
	rvct.reserve(len - middle);

	std::vector<int>::iterator it = vct.begin();

	int i = 0;

	for(; i < len; i++)
	{
		if (i < middle)
		{
			lvct.push_back(*it);
		}
		else
		{
			rvct.push_back(*it);
		}
		it++;
	}
	mergeSort_vct(lvct);
	mergeSort_vct(rvct);
	merge_vct(vct, rvct, lvct);
}

// Mergesort for deque
void PmergeMe::merge_dqe(std::deque<int> &dqe, std::deque<int> rdqe, std::deque<int> ldqe)
{
	std::deque<int>::iterator itl = ldqe.begin();
	std::deque<int>::iterator itr = rdqe.begin();
	
	int i = 0;
	while (itl != ldqe.end() && itr != rdqe.end())
	{
		if (*itl <= *itr)
		{
			dqe[i] = *itl;
			i++;
			itl++;
		}
		else
		{
			dqe[i] = *itr;
			i++;
			itr++;
		}
	}
	while (itl != ldqe.end())
	{
		dqe[i] = *itl;
		i++;
		itl++;
	}
	while (itr != rdqe.end())
	{
		dqe[i] = *itr;
		i++;
		itr++;
	}
}

void PmergeMe::mergeSort_dqe(std::deque<int> &dqe)
{
	int len = dqe.size();
	if (len <= 1)
	{
		return ;
	}
	int middle = len / 2;
	std::deque<int> ldqe;
	std::deque<int> rdqe;

	std::deque<int>::iterator it = dqe.begin();

	int i = 0;

	for(; i < len; i++)
	{
		if (i < middle)
		{
			ldqe.push_back(*it);
		}
		else
		{
			rdqe.push_back(*it);
		}
		it++;
	}
	mergeSort_dqe(ldqe);
	mergeSort_dqe(rdqe);
	merge_dqe(dqe, rdqe, ldqe);
}

void PmergeMe::mergeSort()
{
	std::vector<int> temp_vct = _vct;
	std::deque<int> temp_dqe = _dqe;

	std::cout << "Before:		";
	print_vector(temp_vct);
	std::cout << "After (vector):	";
	mergeSort_vct(temp_vct);
	print_vector(temp_vct);

	std::cout << "After (deque):	";
	mergeSort_dqe(temp_dqe);
	print_deque(temp_dqe);

	time_t start_vct = get_time_microseconds();
	mergeSort_vct(_vct);
	time_t end_vct = get_time_microseconds();
	std::cout << "Time to process a range of " << _vct.size() << " elements with std::vector : " << (end_vct - start_vct) << " us" << std::endl;

	time_t start_dqe = get_time_microseconds();
	mergeSort_dqe(_dqe);
	time_t end_dqe = get_time_microseconds();
	std::cout << "Time to process a range of " << _dqe.size() << " elements with std::deque  : " << (end_dqe - start_dqe) << " us" << std::endl;
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

std::deque<int> &PmergeMe::get_dqe()
{
	return (_dqe);
}

time_t	PmergeMe::get_time_microseconds()
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}