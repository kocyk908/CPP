/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:21:58 by lkoc              #+#    #+#             */
/*   Updated: 2024/10/08 20:57:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pbook.hpp"

void add_contact(Contact contacts[], int& i)
{
    if (i >= 8)
    {
        for (int j = 7; j > 0; j--)
        {
            contacts[j] = contacts[j - 1];  // Przesuwamy każdy kontakt o jedno miejsce w dół
        }
    }
    else
    {
        // Przesuwamy istniejące kontakty w dół, jeśli jeszcze nie osiągnęliśmy limitu
        for (int j = i; j > 0; j--)
        {
            contacts[j] = contacts[j - 1];  // Przesuwamy każdy kontakt o jedno miejsce w dół
        }
        i++;
    }

    // Dodajemy nowy kontakt na pozycję 0
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

    contacts[0].first_name = first_name;
    contacts[0].last_name = last_name;
    contacts[0].nickname = nickname;
    contacts[0].phone_number = phone_number;
    contacts[0].secret = secret;

    std::cout << "Contact added successfully!\n\n";
}