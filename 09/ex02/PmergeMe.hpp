#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <fstream>
# include <vector>
# include <deque>
# include <cstdlib>
# include <sys/time.h>
# include <ctime>

class PmergeMe{
	private:
		std::vector<int> _vct;
		std::deque<int> _deq;
	public:
		PmergeMe();
		PmergeMe(char **args, int count);

		PmergeMe(const PmergeMe& other);
		~PmergeMe();
		PmergeMe&	operator=(const PmergeMe& other);

		std::vector<int> &get_vct();
		std::deque<int> &get_deq();
		
		time_t get_time_microseconds();

		void mergeSort();

};

void 	merge_insert_vec(std::vector<int> &vct);
void 	merge_insert_deq(std::deque<int> &deq);
void print_vector(std::vector<int>& v);
void print_deque(std::deque<int>& d);

#endif