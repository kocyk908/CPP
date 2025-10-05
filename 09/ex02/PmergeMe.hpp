#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <fstream>
# include <vector>
# include <deque>
# include <cstdlib>
# include <sys/time.h>

class PmergeMe{
	private:
		std::vector<int> _vct;
		std::deque<int> _dqe;
	public:
		PmergeMe();
		PmergeMe(char **args, int count);

		PmergeMe(const PmergeMe& other);
		~PmergeMe();
		PmergeMe&	operator=(const PmergeMe& other);

		std::vector<int> &get_vct();
		std::deque<int> &get_dqe();
		
		time_t get_time_microseconds();

		void merge_vct(std::vector<int> &vct, std::vector<int> rvct, std::vector<int> lvct);
		void mergeSort_vct(std::vector<int> &vct);
		void mergeSort_dqe(std::deque<int> &dqe);
		void merge_dqe(std::deque<int> &dqe, std::deque<int> rdqe, std::deque<int> ldqe);
		void mergeSort();

};

void print_vector(std::vector<int>& v);
void print_deque(std::deque<int>& d);

#endif