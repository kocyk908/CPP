#include "PmergeMe.hpp"

void	merge_insert_deq(std::deque<int> &deq)
{
	//print_deque(deq);

	if (deq.size() < 2)
		return ;
	std::deque<int> main;
	std::deque<int> pend;


	for (size_t i = 0; i < deq.size(); i += 2)
	{
		if (i + 1 == deq.size())
			pend.push_back(deq[i]);
		else if (deq[i] > deq[i+1])
		{
			main.push_back(deq[i]);
			pend.push_back(deq[i+1]);
		}
		else
		{
			main.push_back(deq[i+1]);
			pend.push_back(deq[i]);
		}
	}
	//std::cout << "[" << "]" << " main: " << std::endl;
	//print_deque(main);
	//std::cout << "[" << "]" << " pent: " << std::endl;
	//print_deque(pend);
	
	merge_insert_deq(main);

	//std::cout << "end [" << "]" << " main: " << std::endl;
	//print_deque(main);
	//std::cout << "end [" << "]" << " pent: " << std::endl;
	//print_deque(pend);

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
	//std::cout << "order : " << std::endl;
	//print_vector(order);

	for (size_t i = 0; i < pend.size(); i++)
    {
        std::deque<int>::iterator pos = std::lower_bound(main.begin(), main.end(), pend[order[i]]);
		//std::cout << "wstawiona liczba: [" << pend[order[i]] << "] ";
        main.insert(pos, pend[order[i]]);
    }
	deq.assign(main.begin(), main.end());
	return ;
}