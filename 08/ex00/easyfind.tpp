#include "easyfind.hpp"

template <typename T>
void	easyfind(T one, int sec)
{
    typename T::iterator iter = std::find(one.begin(), one.end(), sec);

    if (iter == one.end())
	{
        throw std::exception();
    }
    std::cout << "Value " << sec << " found!" << std::endl;
}