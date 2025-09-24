#ifndef CONV_HPP
# define CONV_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <iomanip> 
# include <climits>

class Conv
{
	private:
		Conv();
		Conv(const Conv &src);
		~Conv();
		Conv &operator=(const Conv &src);
	
	public:
		static void convert(std::string const& literal);
		
};

#endif