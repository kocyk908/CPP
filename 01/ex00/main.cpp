/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoc <lkoc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:43:44 by lkoc              #+#    #+#             */
/*   Updated: 2024/12/14 13:53:30 by lkoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	*zombiePtr;
	
	zombiePtr = NULL;
	zombiePtr = zombiePtr->newZombie("HeapZ");
	zombiePtr->randomChump("StackZ");
	delete (zombiePtr);
}