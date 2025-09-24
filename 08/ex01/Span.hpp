#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <cstddef>
# include <algorithm>

class Span
{
	private:
		std::vector<int>	_array;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		~Span();
		Span&	operator=(const Span& other);

		void	addNumber(int num);
		void	addNumber(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);
		
		int		shortestSpan(void) const;
		int		longestSpan(void) const;

		void	print_vector();
};

#endif