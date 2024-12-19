/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoc <lkoc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:45:34 by babreton          #+#    #+#             */
/*   Updated: 2024/12/19 18:17:05 by lkoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(str name, Weapon &weapon);
		~HumanA();

		void	attack() const;
		
	private:
		str		name;
		Weapon	&weapon;
};

#endif