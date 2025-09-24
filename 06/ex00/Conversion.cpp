#include "conversion.hpp"

Conv::Conv()
{

}

Conv::Conv(const Conv &src)
{
	*this = src;
}

Conv::~Conv()
{

}

Conv &Conv::operator=(const Conv &src)
{
	(void)src;
	return (*this);
}

bool is_pseudoFloat(std::string const& literal)
{
	if (literal == "nanf" || literal == "-inff" || literal == "+inff" || literal == "inff")
		return (true);
	return (false);
}

bool is_pseudoDouble(std::string const& literal)
{
	if (literal == "nan" || literal == "-inf" || literal == "+inf" || literal == "inf")
		return (true);
	return (false);
}

bool is_char(std::string const& literal)
{
    return (literal.size() == 1 && std::isprint(static_cast<char>(literal[0])) && !std::isdigit(static_cast<char>(literal[0])));
}

bool is_int(std::string const& literal)
{
    if (literal.empty())
		return (false);
    size_t i = 0;
	if (literal[0] == '+' || literal[0] == '-')
		i = 1;
    if (i >= literal.size())
		return (false);
	while (i < literal.size())
	{
        if (!std::isdigit(static_cast<char>(literal[i])))
        {
            return (false);
        }   
		i++;
	}
    return (true);
}

bool is_float(std::string const& literal)
{
    if (is_pseudoFloat(literal))
		return (true);
    if (literal.size() < 2 || literal[literal.size()-1] != 'f')
		return (false);
    std::string core = literal.substr(0, literal.size()-1);
    bool hasDigit = false;
	bool dot = false;
    size_t i = 0;
	if (core.size() && (core[0] == '+' || core[0] == '-'))
		i = 1;
    if (i >= core.size())
		return (false);
	while (i < core.size())
	{
        if (core[i] == '.')
		{
			if (dot)
				return (false);
			dot = true;
		}
        else if (std::isdigit(static_cast<char>(core[i])))
			hasDigit = true;
        else
			return (false);
		i++;
	}
    return (hasDigit && dot);
}

bool is_double(std::string const& literal)
{
    if (is_pseudoDouble(literal))
		return (true);
    bool hasDigit = false;
	bool dot = false;
    size_t i = 0;
	if (literal.size() && (literal[0] == '+' || literal[0] == '-'))
		i = 1;
    if (i >= literal.size())
		return (false);
	while(i < literal.size())
	{
		if (literal[i] == '.')
		{
			if (dot)
				return (false);
			dot = true;
		}
        else if (std::isdigit(static_cast<char>(literal[i])))
			hasDigit = true;
        else
			return (false);
		i++;
	}
    return (hasDigit && dot);
}

void Conv::convert(const std::string &literal)
{
    if (literal.empty())
	{
        std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
        return ;
    }

    char *ed = 0;
    double check_value = strtod(literal.c_str(), &ed);
    bool int_overflow = false;

    if (check_value > static_cast<double>(INT_MAX) || check_value < static_cast<double>(INT_MIN))
    {
        int_overflow = true;
    }

    if (is_pseudoFloat(literal) || is_pseudoDouble(literal))
	{
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if (is_pseudoFloat(literal))
		{
            std::cout << "float: " << literal << std::endl;
            std::cout << "double: " << literal.substr(0, literal.size() - 1) << std::endl;
        }
		else
		{
            std::cout << "float: " << literal << "f" << std::endl;
            std::cout << "double: " << literal << std::endl;
        }
        return ;
    }

    if (is_char(literal))
	{
        char i = literal[0];
        std::cout << "char: '" << i << "'" << std::endl;

        std::cout << "int: " << static_cast<int>(i) << std::endl;

        std::cout << std::fixed << std::setprecision(1); // ile liczb po przecinku
        std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;

        std::cout << "double: " << static_cast<double>(i) << std::endl;
        return ;
    }   // char dobrze chyba

    // int
    if (is_int(literal))
	{
        char *end = 0;

        if (int_overflow == true)
        {
            double d = strtod(literal.c_str(), &end);
            if (d < 32 || d > 126)
                std::cout << "char: " << "Non displayable" << std::endl;
            else
                std::cout << "char: " << "'" << static_cast<char>(d) << "'" << std::endl;
            std::cout << "int: " << "impossible" << std::endl;
            std::cout << std::fixed << std::setprecision(1);
            std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
            std::cout << "double: " << d << std::endl;            
        }
        else
        {
            int i = std::atoi(literal.c_str());
            if (i < 32 || i > 126)
                std::cout << "char: " << "Non displayable" << std::endl;
            else
                std::cout << "char: " << "'" << static_cast<char>(i) << "'" << std::endl;
            std::cout << "int: " << i << std::endl;
            std::cout << std::fixed << std::setprecision(1);
            std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(i) << std::endl;
        }
        return ;
    }

    // float
    if (is_float(literal))
	{
        char *end = 0;
        float f = strtof(literal.c_str(), &end);

        if (static_cast<int>(f) < 32 || static_cast<int>(f) > 126)
            std::cout << "char: " << "Non displayable" << std::endl;
        else
            std::cout << "char: " << "'" << static_cast<char>(f) << "'" << std::endl;
        
        if (int_overflow == true)
        {
            std::cout << "int: " << "impossible" << std::endl;
        }
        else
        {
            std::cout << "int: " << static_cast<int>(f) << std::endl;
        }

        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(f) << std::endl; 
        return ;
    }

    // double
    if (is_double(literal))
	{
        char *end = 0;
        double d = strtod(literal.c_str(), &end);

        if (static_cast<int>(d) < 32 || static_cast<int>(d) > 126)
            std::cout << "char: " << "Non displayable" << std::endl;
        else
            std::cout << "char: " << "'" << static_cast<char>(d) << "'" << std::endl;
        
        if (int_overflow == true)
        {
            std::cout << "int: " << "impossible" << std::endl;
        }
        else
        {
            std::cout << "int: " << static_cast<int>(d) << std::endl;
        }

        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
        return ;
    }

    std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
}