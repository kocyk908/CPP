# Nazwa programu
TARGET = phonebook

# Kompilator
CXX = g++

# Flagi kompilatora
CXXFLAGS = -Wall -Wextra -std=c++11

# Pliki nagłówkowe
HEADERS = pbook.hpp

# Pliki źródłowe
SRCS = main.cpp add.cpp utils.cpp

# Pliki obiektowe (po kompilacji)
OBJS = $(SRCS:.cpp=.o)

# Reguła domyślna
all: $(TARGET)

# Reguła kompilacji pliku wykonywalnego
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Reguła kompilacji plików obiektowych
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Reguła czyszcząca pliki obiektowe i binarne
clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean clean-all
