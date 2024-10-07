#include "pbook.hpp"

void add_contact(Contact contacts[], int i)
{
	if (i == 7)
	{
		i = 0;
	}
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string secret;

	std::cout << "Please enter first name: ";
	first_name = add_input(first_name);

	std::cout << "Please enter last name: ";
	last_name = add_input(last_name);

	std::cout << "Please enter nickname: ";
	nickname = add_input(nickname);

	std::cout << "Please enter phone number: ";
	phone_number = add_input(phone_number);

	std::cout << "Please enter secret: ";
	secret = add_input(secret);

	contacts[i].first_name = first_name;
	contacts[i].last_name = last_name;
	contacts[i].nickname = nickname;
	contacts[i].phone_number = phone_number;
	contacts[i].secret = secret;
	contacts[i].index = i;
	std::cout << "Contact added successfully!\n\n";
}