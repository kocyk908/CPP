#include "PmergeMe.hpp"

void	merge_insert_vec(std::vector<int> &vct)
{
	//print_vector(vct);

	if (vct.size() < 2)
		return ;
	std::vector<int> main;
	std::vector<int> pend;


	for (size_t i = 0; i < vct.size(); i += 2)
	{
		if (i + 1 == vct.size())
			pend.push_back(vct[i]);
		else if (vct[i] > vct[i+1])
		{
			main.push_back(vct[i]);
			pend.push_back(vct[i+1]);
		}
		else
		{
			main.push_back(vct[i+1]);
			pend.push_back(vct[i]);
		}
	}
	//std::cout << "[" << "]" << " main: " << std::endl;
	//print_vector(main);
	//std::cout << "[" << "]" << " pent: " << std::endl;
	//print_vector(pend);
	
	merge_insert_vec(main);

	//std::cout << "end [" << "]" << " main: " << std::endl;
	//print_vector(main);
	//std::cout << "end [" << "]" << " pent: " << std::endl;
	//print_vector(pend);

	size_t m = pend.size();
	std::vector<int> order;
    if (m)
	{
        order.reserve(m);
        order.push_back(0);
        if (m > 1)
		{
			size_t j_curr = 1;
            size_t j_prev = 1; //j - jacobsthal
            while(true)
			{
                size_t next  = 2 * j_prev + j_curr;
                size_t start = (next < m) ? next : m;
                for (size_t r = start; r > j_curr; --r)
                    order.push_back(r - 1);
                if (next >= m)
					break;
                j_prev = j_curr;
				j_curr = next;
            }
    	}
	}


	for (size_t i = 0; i < pend.size(); i++)
    {
        std::vector<int>::iterator pos = std::lower_bound(main.begin(), main.end(), pend[order[i]]);
		//std::cout << "wstawiona liczba: [" << pend[order[i]] << "] ";
        main.insert(pos, pend[order[i]]);
    }
	vct = main;

	return ;
}

// dlaczego liczby jacobsthala mają sens
// jak działa binary search

