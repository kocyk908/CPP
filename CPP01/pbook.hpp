#ifndef PBOOK_HPP
#define PBOOK_HPP

#include <iostream>
#include <string>

class Contact
{
public:
	int index;
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string secret;
};

std::string add_input(std::string str);
void add_contact(Contact contacts[], int i);
void search_contact(Contact contacts[], int i);

#endif