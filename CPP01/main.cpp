#include "pbook.hpp"

int main()
{
	int	j = 0;
	int i = 0;
	Contact contacts[8]; 
	while (1)
	{
		std::string command;
		if (j++ == 0)
			std::cout << "Welcome to the PhoneBook! ";
		std::cout << "Choose one of the listed options:\n";
		std::cout << "ADD | SEARCH | EXIT\n";
		std::getline(std::cin, command);
		if (command == "ADD")
		{
			add_contact(contacts, i);
			i++;
		}
		else if (command == "SEARCH")
		{
			if (i == 0)
			{
				std::cout << "No contacts added yet. Please add a contact first.\n";
			}
			else
				search_contact(contacts, i);
		}
		else if (command == "EXIT")
		{
			exit(1);
		}
		else
		{
			std::cout << "Invalid input. Please try again.\n";
		}
	}
}


void display(Contact contacts[], int size)
{
    std::cout << "Index | First name | Last name | Nickname\n";
    for (int i = 0; i < size; i++)
    {
        if (i >= 0 && i < 8) // Sprawdzaj tylko kontakty z indeksem różnym od 0
        {
            std::cout << contacts[i].index << " | ";
            std::cout << contacts[i].first_name << " | ";
            std::cout << contacts[i].last_name << " | ";
            std::cout << contacts[i].nickname << "\n";
        }
    }
}

void search_contact(Contact contacts[], int size)
{
	int id;

	display(contacts, size);
	std::cout << "Which one to display?\n";
	std::cin >> id;
	std::cin.ignore();
	if (id >= 0 && id <= size)
	{
		std::cout << "First name: " << contacts[id].first_name << "\n";
		std::cout << "Last name: " << contacts[id].last_name << "\n";
		std::cout << "Nickname: " << contacts[id].nickname << "\n";
		std::cout << "Phone number: " << contacts[id].phone_number << "\n";
		std::cout << "Secret: " << contacts[id].secret << "\n\n";
	}
	else
	{
		std::cout << "Invalid index. Please try again.\n";
	}
}
//void exit();
