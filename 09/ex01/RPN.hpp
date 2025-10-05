#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <fstream>
# include <stack>
# include <math.h>

class RPN{
	public:
		RPN();
		//RPN(const RPN &other);
		~RPN();
		//RPN	&operator=(const RPN &other);

		void load_expression(std::string expression);

		class NotEnoughValuesException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

};
#endif