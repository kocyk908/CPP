/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoc <lkoc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:38:46 by babreton          #+#    #+#             */
/*   Updated: 2024/12/14 14:13:52 by lkoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int num, std::string name)
{
	int	i;
	Zombie	*horde;
	
	i = 0;
	horde = new Zombie[num];
	while (i < num)
	{
		horde[i].setName(name);
		horde[i].announce();
		i++;
	}
	return (horde);
}