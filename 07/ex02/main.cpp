#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    for (int i = 0; i < (int)numbers.size(); i++)
    {
        std::cout << numbers[i];
    }
    std::cout << std::endl;
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < (int)numbers.size(); i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    Array<int>  copy(numbers);
    for (int i = 0; i < (int)copy.size(); i++)
    {
        if (mirror[i] != copy[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    Array<int>  another_copy = copy;
    for (int i = 0; i < (int)another_copy.size(); i++)
    {
        if (mirror[i] != another_copy[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//

    Array<int> int_array(0);
    std::cout << "size of int array: " << int_array.size() << std::endl;
    for (int i = 0; i < (int)int_array.size(); i++)
        std::cout << int_array[i];
    Array<char> char_array(10);
    std::cout << "size of char array: " << char_array.size() << std::endl;
    for (int i = 0; i < (int)char_array.size(); i++)
        char_array[i] = '0' + i;
    const Array<char> const_array(char_array);
    std::cout << "size of const char array: " << const_array.size() << std::endl;
    for (int i = 0; i < (int)const_array.size(); i++)
        std::cout << const_array[i];
    std::cout << std::endl;
    return 0;
}