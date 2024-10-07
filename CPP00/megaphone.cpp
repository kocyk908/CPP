#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char** argv)
{
	char** string;

	string = argv + 1;
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    else
    {
        int j = 0;
		int i = 0;
        while (string[i])
        {
            j = 0;
            while (string[i][j])
            {
                std::cout << (char)toupper(string[i][j]);
                j++;
            }
            i++;
		}
        std::cout << std::endl;
    }
    return (0);
}
