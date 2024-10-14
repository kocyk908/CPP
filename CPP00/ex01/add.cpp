/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoc <lkoc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:21:58 by lkoc              #+#    #+#             */
/*   Updated: 2024/10/14 19:45:20 by lkoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pbook.hpp"

void add_contact(Contact contacts[], int& i)
{
    // Sprawdzamy, czy liczba kontaktów osiągnęła maksymalny limit
    if (i >= 8)
    {
        // Przesuwamy istniejące kontakty w dół, zastępując najstarszy
        for (int j = 7; j > 0; j--)
        {
            contacts[j] = contacts[j - 1];
        }
    }
    else
    {
        for (int j = i; j > 0; j--)
        {
            contacts[j] = contacts[j - 1];
        }
        i++;
    }

    // Pobieramy dane użytkownika
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

    // Przypisanie wartości za pomocą setterów
    contacts[0].set_first_name(first_name);
    contacts[0].set_last_name(last_name);
    contacts[0].set_nickname(nickname);
    contacts[0].set_phone_number(phone_number);
    contacts[0].set_secret(secret);

    std::cout << "Contact added successfully!\n\n";
}
