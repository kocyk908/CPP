/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoc <lkoc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:34:32 by lkoc              #+#    #+#             */
/*   Updated: 2024/11/08 17:48:11 by lkoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl Yapping;
	Yapping.complain("DEBUG");
	Yapping.complain("INFO");
	Yapping.complain("WARNING");
	Yapping.complain("ERROR");
	return (0);
}
