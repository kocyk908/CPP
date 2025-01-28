/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:19:17 by lkoc              #+#    #+#             */
/*   Updated: 2025/01/28 23:02:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include "Brain.hpp"

#include <stdio.h>

int	main()
{
	Animal	*array[100];
	
	int		i = 0;

	while (i < 50)
		array[i++] = new Dog();
	while (i < 100)
		array[i++] = new Cat();

	printf("\n\n###### Dogs and Cats are created\n\n");
	array[10]->makeSound();
	array[90]->makeSound();

	printf("\n\n###### Dogs and Cats are deleted\n\n");
	for (i = 0; i < 100; i++)
        delete array[i];
		
	return (0);
}