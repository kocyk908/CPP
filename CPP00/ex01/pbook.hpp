/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pbook.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoc <lkoc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:21:56 by lkoc              #+#    #+#             */
/*   Updated: 2024/10/14 19:26:57 by lkoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PBOOK_HPP
#define PBOOK_HPP

#include <iostream>
#include <string>

class Contact
{
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
        void set_secret(std::string secret);
        void set_phone_number(std::string number);

        const std::string& get_first_name() const;
        const std::string& get_last_name() const;
        const std::string& get_nickname() const;
        const std::string& get_phone_number() const;
        const std::string& get_secret() const;
};

std::string add_input(std::string str);
void add_contact(Contact contacts[], int& i);
void search_contact(Contact contacts[], int i);
void print_to_10_chars(std::string str);
void display(Contact contacts[], int size);
void search_contact(Contact contacts[], int size);

#endif
