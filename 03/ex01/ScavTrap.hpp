/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoc <lkoc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:19:17 by lkoc              #+#    #+#             */
/*   Updated: 2025/01/11 18:40:09 by lkoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	// data inherided from protected

	public:
		// constructors and destructor are inherited from ClapTrap
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &other);
		ScavTrap &operator = (const ScavTrap &other);
		~ScavTrap();

		void attack(const std::string &target);
		void guardGate(void);
};

#endif