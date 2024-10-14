/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoc <lkoc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:57:54 by lkoc              #+#    #+#             */
/*   Updated: 2024/10/14 18:57:54 by lkoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pbook.hpp"

void display(Contact contacts[], int size)
{
    std::cout << "     Index|First name| Last name|  Nickname|\n";
	std::cout << "--------------------------------------------\n";
    for (int i = 0; i < size; i++)
    {
        if (i >= 0 && i < 8)
        {
			std::cout << "         " << i + 1;
			std::cout << "|";
			print_to_10_chars(contacts[i].first_name);
			std::cout << "|";
			print_to_10_chars(contacts[i].last_name);
			std::cout << "|";
			print_to_10_chars(contacts[i].nickname);
			std::cout << "|\n";
		}
    }
}

void search_contact(Contact contacts[], int size)
{
	int id;

	std::cout << "Which one to display?\n";
	std::cin >> id;
	std::cin.ignore();
	if (id >= 1 && id <= size)
	{
		std::cout << "First name: " << contacts[id - 1].first_name << "\n";
		std::cout << "Last name: " << contacts[id - 1].last_name << "\n";
		std::cout << "Nickname: " << contacts[id - 1].nickname << "\n";
		std::cout << "Phone number: " << contacts[id - 1].phone_number << "\n";
		std::cout << "Secret: " << contacts[id - 1].secret << "\n\n";
	}
	else
	{
		std::cout << "Invalid index. Please try again.\n";
	}
}
