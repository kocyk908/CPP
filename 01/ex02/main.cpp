/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:45:37 by lkoc              #+#    #+#             */
/*   Updated: 2025/01/03 00:15:24 by marvin           ###   ########.fr       */
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