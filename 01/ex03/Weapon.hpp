/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoc <lkoc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:45:33 by babreton          #+#    #+#             */
/*   Updated: 2024/12/19 18:16:49 by lkoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <iostream>

typedef std::string str;

class Weapon
{
	public:
		Weapon();
		Weapon(str type);
		~Weapon();

		const str	&getType() const;
		void		setType(str ntype);
	private:
		str	type;
};

#endif