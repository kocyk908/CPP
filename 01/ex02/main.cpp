/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoc <lkoc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:45:37 by lkoc              #+#    #+#             */
/*   Updated: 2025/01/04 13:54:07 by lkoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string hello = "HI THIS IS BRAIN";

	std::string *ptr = &hello;
	std::string &ref = hello;

	std::cout << "Memory address of the string: " << &hello << std::endl;
	std::cout << "Memory address held by pointer: " << ptr << std::endl;
	std::cout << "Memory address held by reference: " << &ref << std::endl;

	std::cout << "Value of the string: " << hello << std::endl;
	std::cout << "Value pointed to by pointer: " << *ptr << std::endl;
	std::cout << "Value pointed to by reference: " << ref << std::endl;

	return (0);
}