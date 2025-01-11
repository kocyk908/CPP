/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoc <lkoc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:19:17 by lkoc              #+#    #+#             */
/*   Updated: 2025/01/11 18:17:46 by lkoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	hit_points = 10;
	energy_points = 10;
	attack_damage = 0;
	std::cout << "ClapTrap " << this->name << " created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
}

ClapTrap &ClapTrap::operator = (const ClapTrap &other)
{
	this->name = other.name;
	hit_points = other.hit_points;
	energy_points = other.energy_points;
	attack_damage = other.attack_damage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " destroyed" << std::endl;
}

// attack/repair/take_dmg


void ClapTrap::attack(const std::string &target)
{
	if (energy_points > 0 && hit_points > 0) 
	{
		std::cout << "ClapTrap " << name << " attacks ClapTrap " << target << std::endl;
		energy_points -= 1;
	}
	else if (hit_points <= 0)
		std::cout << "ClapTrap " << name << " is dead and can't attack" << std::endl;
	else
		std::cout << "ClapTrap " << name << " energy is too low to attack" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energy_points > 0 && hit_points > 0)
	{
		std::cout << "ClapTrap " << name << " gains " << amount << " points of health" << std::endl;
		hit_points += amount;
		energy_points--;
	}
	else if (hit_points <= 0)
		std::cout << "ClapTrap " << name << " is dead and can't be repaired" << std::endl;
	else
		std::cout << "ClapTrap " << name << " energy is too low to repair itself" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hit_points > 0)
	{
		std::cout << "ClapTrap " << name << " takes " << amount << " hit points" << std::endl;
		hit_points -= amount;
		if (hit_points <= 0)
			std::cout << "ClapTrap " << name << " has been killed" << std::endl;
	}
	else
		std::cout << "ClapTrap " << name << " is dead and can't take more damage" << std::endl;
}