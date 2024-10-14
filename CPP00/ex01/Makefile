TARGET = phonebook

CC = g++

CFLAGS = -Wall -Wextra -std=c++11

HEADERS = pbook.hpp

SRCS = main.cpp add.cpp utils.cpp search.cpp getset.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS) $(TARGET)

re: fclean all

.PHONY: all clean clean-all
