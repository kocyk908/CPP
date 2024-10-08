/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pbook.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:21:56 by lkoc              #+#    #+#             */
/*   Updated: 2024/10/08 21:16:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PBOOK_HPP
#define PBOOK_HPP

#include <iostream>
#include <string>

class Contact
{
	public:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string secret;
};

std::string add_input(std::string str);
void 		add_contact(Contact contacts[], int& i);
void 		search_contact(Contact contacts[], int i);
void 		print_to_10_chars(std::string str);
void 		display(Contact contacts[], int size);
void 		search_contact(Contact contacts[], int size);

#endif