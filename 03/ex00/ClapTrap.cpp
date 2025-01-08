/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:19:17 by lkoc              #+#    #+#             */
/*   Updated: 2025/01/07 23:55:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->Hit_points = 10;
	this->Enerty_points = 10;
	this->Attack_damage = 0;
	std::cout << "ClapTrap " << this->name << " created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
}

ClapTrap &ClapTrap::operator = (const ClapTrap &other)
{
	this->name = other.name;
	this->Hit_points = other.Hit_points;
	this->Enerty_points = other.Enerty_points;
	this->Attack_damage = other.Attack_damage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->name << " destroyed" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->Hit_points > 0 && this->Enerty_points > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->Attack_damage << " points of damage!" << std::endl;
		this->Enerty_points--;
	}
	else
		std::cout << "ClapTrap " << this->name << " is dead" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->Hit_points > 0)
	{
		this->Hit_points -= amount;
		std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
		if (this->Hit_points <= 0)
			std::cout << "ClapTrap " << this->name << " is dead" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->name << " is dead" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->Hit_points > 0 && this->Enerty_points > 0)
	{
		this->Hit_points += amount;
		std::cout << "ClapTrap " << this->name << " is repaired by " << amount << " points!" << std::endl;
		this->Enerty_points--;
	}
	else
		std::cout << "ClapTrap " << this->name << " is dead" << std::endl;
}