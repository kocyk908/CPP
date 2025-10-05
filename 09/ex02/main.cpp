#include "PmergeMe.hpp"

int main(int ac, char** av)
{
	PmergeMe merge(av + 1, ac - 1);

	merge.mergeSort();
	return (0);
}