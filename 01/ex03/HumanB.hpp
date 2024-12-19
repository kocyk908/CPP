/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoc <lkoc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:45:37 by babreton          #+#    #+#             */
/*   Updated: 2024/12/19 18:16:58 by lkoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(str name);
		~HumanB();
		
		void	attack() const;
		void	setWeapon(Weapon &weapon);
	private:
		str		name;
		Weapon	*weapon;
};

#endif