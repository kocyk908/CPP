#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

# include <iostream>
# include <stdint.h>

struct Data
{
	bool status;
    std::string type;
    int value;
};

class Serializer {
    private:
        Serializer();
        Serializer(const Serializer &copy);
        ~Serializer();
        Serializer &operator=(const Serializer &copy);

    public:
        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);
};

#endif