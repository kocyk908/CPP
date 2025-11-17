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

		for (std::size_t i = 0; i < order.size(); ++i)
		{
			std::size_t value_id = order[i];
			int value = pend[value_id];

			size_t low = 0;
			size_t high = main.size();
			while (low < high)
			{
				size_t mid = low + (high - low) / 2;
				if (value > main[mid])
				{
					low = mid + 1;
				}
				else
				{
					high = mid;
				}
			}
			main.insert(main.begin() + static_cast<std::ptrdiff_t>(low), value);
		}
	}
	vct = main;
}