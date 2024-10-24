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
	std::cout << "Creating a new zombie on HEAP with 'newZombie'" << std::endl;
	Zombie* HeapZombie = newZombie("FirstZombie");
	HeapZombie->announce();
	delete HeapZombie;

	std::cout << "Creating a new zombie on STACK with 'randomChump'" << std::endl;
	randomChump("RandomZombie");
	return (0);
}
