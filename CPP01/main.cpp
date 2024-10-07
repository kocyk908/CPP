#include <iostream>

class Contact
{
public:
	std::string first_name;
	std::string last_name;
	std::string phone_number;
	std::string secret;
};

void add_contact(Contact contacts[], int i);

int main()
{
	int i = 1;
	Contact contacts[8]; 
	std::string command;
	std::cout << "Welcome to the PhoneBook!\n";
	std::cout << "Please print option from listed below:\n";
	std::cout << "ADD | SEARCH | EXIT\n";
	std::getline(std::cin, command);
	if (command == "ADD")
	{
		add_contact(contacts, i);
		std::cout << contacts[i].first_name;
		i++;
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

std::string add_input(std::string str)
{
	int i = 0;
	std::getline(std::cin, str);
	while (str.empty())
	{
		if (i == 0)
		{
			std::cout << "You can't leave blank field. Please try again: \n";
			i++;
		}
		std::getline(std::cin, str);
	}
	return (str);

}

void add_contact(Contact contacts[], int i)
{
	
	if (i == 8)
	{
		i = 1;
	}
	std::string first_name;
	std::string last_name;
	std::string phone_number;
	std::string secret;
	std::cout << "Please enter first name: ";
	first_name = add_input(first_name);
	std::cout << "Please enter last name: ";
	last_name = add_input(last_name);
	std::cout << "Please enter phone number: ";
	phone_number = add_input(phone_number);
	std::cout << "Please enter secret: ";
	secret = add_input(secret);

	contacts[i].first_name = first_name;
	contacts[i].last_name = last_name;
	contacts[i].phone_number = phone_number;
	contacts[i].secret = secret;
	std::cout << "Contact added successfully!\n";
}
//void search_contact();
//void exit();
