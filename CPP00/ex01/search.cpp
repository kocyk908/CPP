/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:57:54 by lkoc              #+#    #+#             */
/*   Updated: 2024/10/17 23:37:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pbook.hpp"

void PhoneBook::search_contact()
{
    display(contacts, contact_count);

    int id;
    std::cout << "Which one to display?\n";
    std::cin >> id;
    std::cin.ignore();
    if (id >= 1 && id <= contact_count)
    {
        std::cout << "Displaying contact with index " << id << ":\n";
        std::cout << "First name: " << contacts[id - 1].get_first_name() << "\n";
        std::cout << "Last name: " << contacts[id - 1].get_last_name() << "\n";
        std::cout << "Nickname: " << contacts[id - 1].get_nickname() << "\n";
        std::cout << "Phone number: " << contacts[id - 1].get_phone_number() << "\n";
        std::cout << "Secret: " << contacts[id - 1].get_secret() << "\n\n";
    }
    else
    {
        std::cout << "Invalid index. Please try again.\n";
    }
}

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
            print_to_10_chars(contacts[i].get_first_name());
            std::cout << "|";
            print_to_10_chars(contacts[i].get_last_name());
            std::cout << "|";
            print_to_10_chars(contacts[i].get_nickname());
            std::cout << "|\n";
        }
    }
}