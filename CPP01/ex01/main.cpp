/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:55:13 by lkoc              #+#    #+#             */
/*   Updated: 2024/10/26 11:10:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	//input
	int N = 10;

 	Zombie* horde = zombieHorde(N, "Zombie");
	if (horde)
	{
		for (int i = 0; i < N; i++)
			horde[i].announce(i);
		delete[] horde;
	}
	return (0);
}