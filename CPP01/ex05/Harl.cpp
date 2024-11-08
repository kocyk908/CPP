/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoc <lkoc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:34:37 by lkoc              #+#    #+#             */
/*   Updated: 2024/11/08 17:56:05 by lkoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp" 

void Harl::complain(std::string level)
{
	Harl harl;
	std::string lvls[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	for (int i = 0; i < 4; i++)
	{
		if (lvls[i] == level)
		{
			harl.*lvls[i];
			break;
		}
	}
	return (0);
}