/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:19:17 by lkoc              #+#    #+#             */
/*   Updated: 2025/01/26 22:49:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include "Brain.hpp"

#include <stdio.h>

int main()
{
	printf("######## WrongAnimal tests\n");
	WrongAnimal	*unknown = new WrongAnimal();
	std::cout << unknown->getType() << " " << std::endl;
	unknown->makeSound();

	printf("\n######## WrongCat tests\n");
	WrongAnimal	*unknown2 = new WrongCat();
	std::cout << unknown2->getType() << " " << std::endl;
	unknown2->makeSound();

	printf("\n######## Dog tests\n");
	Animal		*dog = new Dog();
	std::cout << dog->getType() << " " << std::endl;
	dog->makeSound();

	printf("\n######## Animal tests\n");
	Animal	*meta = new Animal();
	std::cout << meta->getType() << " " << std::endl;
	meta->makeSound();

	printf("\n######## Cat tests\n");
	Animal	*cat = new Cat();
	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound();

	printf("\n####### cleaning up\n");
	delete meta;
	delete cat;
	delete dog;
	delete unknown;
	delete unknown2;
	return (0);
}