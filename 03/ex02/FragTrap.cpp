/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:57:55 by lkoc              #+#    #+#             */
/*   Updated: 2025/01/15 22:42:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap " << this->name << " created" << std::endl;
}

FragTrap::FragTrap(const ClapTrap &other) : ClapTrap(other)
{
	*this = other;
}

FragTrap &FragTrap::operator = (const FragTrap &other)
{
	this->name = other.name;
	hit_points = other.hit_points;
	energy_points = other.energy_points;
	attack_damage = other.attack_damage;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " destroyed" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (energy_points > 0 && hit_points > 0) 
	{
		std::cout << "FragTrap " << name << " attacks " << target << std::endl;
		energy_points -= 1;
	}
	else if (hit_points <= 0)
		std::cout << "FragTrap " << name << " is dead and can't attack" << std::endl;
	else
		std::cout << "FragTrap " << name << " energy is too low to attack" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << " said 'WE DID IT, HIGH FIVE BRO!'" << std::endl;
}
