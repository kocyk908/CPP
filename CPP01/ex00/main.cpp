/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoc <lkoc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:39:25 by lkoc              #+#    #+#             */
/*   Updated: 2024/10/21 20:45:01 by lkoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

int main(void)
{
	std::cout << "Creating a new zombie with 'newZombie'" << std::endl;
	Zombie* OneZombie = newZombie("FirstZombie");
	heapZombie->announce();
	delete heapZombie;

	std::cout << "Creating a new zombie with 'randomChump'" << std::endl;
	randomChump("RandomZombie");
	return (0);
}
