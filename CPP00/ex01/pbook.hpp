/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pbook.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:21:56 by lkoc              #+#    #+#             */
/*   Updated: 2024/10/17 23:37:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PBOOK_HPP
#define PBOOK_HPP

#include <iostream>
#include <string>

class Contact {
private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string secret;

public:
    void set_first_name(std::string firstname);
    void set_last_name(std::string lastname);
    void set_nickname(std::string nickname);
    void set_phone_number(std::string number);
    void set_secret(std::string secret);

    const std::string& get_first_name() const;
    const std::string& get_last_name() const;
    const std::string& get_nickname() const;
    const std::string& get_phone_number() const;
    const std::string& get_secret() const;
};

class PhoneBook {
private:
    Contact contacts[8];
    int contact_count;

public:
    PhoneBook();
    void add_contact();
    void search_contact();
};

std::string add_input(std::string str);
void print_to_10_chars(std::string str);
void display(Contact contacts[], int size); // Dodaj tę linię

#endif