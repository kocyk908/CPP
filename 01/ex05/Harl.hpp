/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoc <lkoc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 09:47:11 by babreton          #+#    #+#             */
/*   Updated: 2024/12/19 18:18:38 by lkoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

typedef std::string str;

class Harl
{
	public:
		Harl();
		~Harl();

		void	complain(str level);

	private:
		void	debug() const;
		void	info() const;
		void	warning() const;
		void	error() const;
};

#endif