/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:55:15 by lkoc              #+#    #+#             */
/*   Updated: 2024/10/26 11:09:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : name()
{
}

Zombie::~Zombie()
{
    // Możesz dodać kod czyszczący tutaj, jeśli jest to potrzebne
}

void Zombie::setName(std::string name)
{
	this->name = name;
}

void Zombie::announce(int i)
{
	std::cout << name << i <<" BraiiiiiiinnnzzzZ..." << std::endl;
}