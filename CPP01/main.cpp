#include <iostream>

void add_contact();

int main()
{
	std::string command;
	std::cout << "Welcome to the PhoneBook!\n";
	std::cout << "Please print option from listed below:\n";
	std::cout << "ADD | SEARCH | EXIT\n";
	std::getline(std::cin, command);
	if (command == "ADD")
	{
		add_contact();
	}
	else if (command == "SEARCH")
	{
		//search_contact();
	}
	else if (command == "EXIT")
	{
		std::cout << 3;
		exit(1);
	}
	else
	{
		std::cout << "Invalid input. Please try again.\n";
	}
}


void add_contact()
{
	std::string first_name;
	std::string last_name;
	std::string phone_number;
	std::string secret;
	std::cout << "Please enter first name: ";
	std::getline(std::cin, first_name);
	std::cout << "Please enter last name: ";
	std::getline(std::cin, last_name);
	std::cout << "Please enter phone number: ";
	std::getline(std::cin, phone_number);
	std::cout << "Please enter secret: ";
	std::getline(std::cin, secret);

	std::cout << "Contact added successfully!\n"; 
}
//void search_contact();
//void exit();
