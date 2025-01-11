/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoc <lkoc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:19:17 by lkoc              #+#    #+#             */
/*   Updated: 2025/01/11 18:51:58 by lkoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap a("A");
	ClapTrap b("B");
	ScavTrap c("C");
	ScavTrap d("D");

	a.attack("B");
	b.takeDamage(1);
	b.beRepaired(1);
	c.attack("D");
	d.guardGate();

	
	return (0);
}