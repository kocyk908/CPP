/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoc <lkoc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:45:27 by babreton          #+#    #+#             */
/*   Updated: 2024/12/19 18:16:43 by lkoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {
}

Weapon::Weapon(str type) {
	this->type = type;
}

Weapon::~Weapon() {
	
}

const str	&Weapon::getType() const {
	return this->type;
}


void	Weapon::setType(str ntype) {
	this->type = ntype;
}
