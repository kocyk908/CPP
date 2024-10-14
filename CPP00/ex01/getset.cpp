/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getset.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoc <lkoc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:27:26 by lkoc              #+#    #+#             */
/*   Updated: 2024/10/14 19:27:26 by lkoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pbook.hpp"

// Settery
void Contact::set_first_name(std::string firstname)
{
    first_name = firstname;
}

void Contact::set_last_name(std::string lastname)
{
    last_name = lastname;
}

void Contact::set_nickname(std::string nickname)
{
    this->nickname = nickname;
}

void Contact::set_secret(std::string secret)
{
    this->secret = secret;
}

void Contact::set_phone_number(std::string number)
{
    phone_number = number;
}

// Gettery
const std::string& Contact::get_first_name() const
{
    return first_name;
}

const std::string& Contact::get_last_name() const
{
    return last_name;
}

const std::string& Contact::get_nickname() const
{
    return nickname;
}

const std::string& Contact::get_phone_number() const
{
    return phone_number;
}

const std::string& Contact::get_secret() const
{
    return secret;
}