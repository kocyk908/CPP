/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:57:58 by lkoc              #+#    #+#             */
/*   Updated: 2025/01/15 22:33:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(std::string name);
		FragTrap(const ClapTrap &other);
		FragTrap &operator = (const FragTrap &other);
		// virtual for future changes in ScavTrap
		~FragTrap();
		
		void attack(const std::string &target);
		void highFivesGuys(void);
};

#endif