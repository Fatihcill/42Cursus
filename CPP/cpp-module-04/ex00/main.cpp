/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 12:16:38 by fcil              #+#    #+#             */
/*   Updated: 2022/08/14 15:13:48 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Animal const	*meta = new Animal();
	Animal const	*j = new Dog();
	Animal const	*i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	const WrongAnimal *wrong_cat = new WrongCat();

	std::cout << std::endl;
	wrong_cat->makeSound();
	std::cout << std::endl;

	delete meta;
	delete j;
	delete i;
	return (0);
}
