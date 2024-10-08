/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoc <lkoc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:21:54 by lkoc              #+#    #+#             */
/*   Updated: 2024/10/07 21:21:54 by lkoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		}
		else if (command == "SEARCH")
		{
			if (i == 0)
			{
				std::cout << "No contacts added yet. Please add a contact first.\n";
			}
			else
			{
				display(contacts, i);
				search_contact(contacts, i);
			}
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

void print_to_10_chars(std::string str)
{
	int x = str.length();

	if (str.length() > 10)
	{
		std::cout << str.substr(0, 9) << ".";
	}
	else
	{
		for (int i = 0; i < 10 - x; i++)
		{
			std::cout << " ";
		}
		std::cout << str;
	}
}
