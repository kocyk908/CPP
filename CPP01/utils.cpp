/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoc <lkoc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:21:52 by lkoc              #+#    #+#             */
/*   Updated: 2024/10/07 21:21:52 by lkoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pbook.hpp"

std::string add_input(std::string str)
{
	int i = 0;
	std::getline(std::cin, str);
	while (str.empty())
	{
		if (i == 0)
		{
			std::cout << "You can't leave blank field. Please try again: \n";
			i++;
		}
		std::getline(std::cin, str);
	}
	return (str);

}