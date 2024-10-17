/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:21:58 by lkoc              #+#    #+#             */
/*   Updated: 2024/10/17 23:38:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pbook.hpp"

PhoneBook::PhoneBook() : contact_count(0) {}

void PhoneBook::add_contact()
{
    if (contact_count >= 8)
    {
        for (int j = 7; j > 0; j--)
        {
            contacts[j] = contacts[j - 1];
        }
    }
    else
    {
        for (int j = contact_count; j > 0; j--)
        {
            contacts[j] = contacts[j - 1];
        }
        contact_count++;
    }

    std::string first_name, last_name, nickname, phone_number, secret;

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

    contacts[0].set_first_name(first_name);
    contacts[0].set_last_name(last_name);
    contacts[0].set_nickname(nickname);
    contacts[0].set_phone_number(phone_number);
    contacts[0].set_secret(secret);

    std::cout << "Contact added successfully!\n\n";
}