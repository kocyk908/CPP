#include "PmergeMe.hpp"

void	merge_insert_vec(std::vector<int> &vct)
{
	if (vct.size() < 2)
		return ;
	std::vector<int> main;
	main.reserve(vct.size() / 2);
	std::vector<int> pend;
	pend.reserve(vct.size() - main.capacity());

	// std::cout << "vct: " << vct.size() << " main: " << main.capacity() << " pend: " << pend.capacity() << std::endl;

	for (std::size_t i = 0; i < vct.size(); i += 2)
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
	
	merge_insert_vec(main);

	const std::size_t m = pend.size();
    if (m)
	{
		std::vector<std::size_t> order;
        order.reserve(m);
        order.push_back(0);
        if (m > 1)
		{
			std::size_t j_curr = 1;
            std::size_t j_prev = 1; //j - jacobsthal
            while(true)
			{
                std::size_t next  = 2 * j_prev + j_curr;
                std::size_t start = (next < m) ? next : m;
                for (std::size_t r = start; r > j_curr; --r)
                    order.push_back(r - 1);
                if (next >= m)
					break;
                j_prev = j_curr;
				j_curr = next;
            }
    	}

		// for (std::size_t i = 0; i < pend.size(); i++)
		// {
		// 	std::vector<int>::iterator pos = std::lower_bound(main.begin(), main.end(), pend[order[i]]);
		// 	//std::cout << "wstawiona liczba: [" << pend[order[i]] << "] ";
		// 	main.insert(pos, pend[order[i]]);
		// }
		for (std::size_t t = 0; t < order.size(); ++t)
		{
			std::size_t idx = order[t];
			int x = pend[idx];

			std::size_t lo = 0, hi = main.size();
			while (lo < hi)
			{
				std::size_t mid = lo + (hi - lo) / 2;
				if (main[mid] < x)
					lo = mid + 1;
				else
					hi = mid;
			}
			main.insert(main.begin() + static_cast<std::ptrdiff_t>(lo), x);
		}
	}
	vct = main;
}

// dlaczego liczby jacobsthala mają sens
// jak działa binary search

