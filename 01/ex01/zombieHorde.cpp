/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:45:37 by lkoc              #+#    #+#             */
/*   Updated: 2025/01/03 00:15:18 by marvin           ###   ########.fr       */
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