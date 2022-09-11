/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 12:16:38 by fcil              #+#    #+#             */
/*   Updated: 2022/09/11 16:06:05 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Animal *tab[4];
	Brain *cat_brain;
	Brain *dog_brain;

	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
		{
			tab[i] = new Dog();
			tab[i]->makeSound();
		}
		else
		{
			tab[i] = new Cat();
			tab[i]->makeSound();
		}
	}
	dog_brain = tab[0]->getBrain();
	cat_brain = tab[2]->getBrain();
	cat_brain->ideas[0] = dog_brain->ideas[0] = "IDEA1";
	cat_brain->ideas[1] = dog_brain->ideas[1] = "IDEA2";
	cat_brain->ideas[2] = dog_brain->ideas[2] = "IDEA3";
	cat_brain->ideas[3] = dog_brain->ideas[3] = "IDEA4";
	cat_brain->ideas[4] = dog_brain->ideas[4] = "IDEA5";
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "|" << tab[0]->getBrain()->ideas[0] << "|" << std::endl;
	*(tab[1]) = *(tab[0]);
	std::cout << "|" << tab[1]->getBrain()->ideas[1] << "|" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "|" << tab[2]->getBrain()->ideas[2] << "|" << std::endl;
	*(tab[3]) = *(tab[2]);
	std::cout << "|" << tab[3]->getBrain()->ideas[3] << "|" << std::endl;
	std::cout << "-----------------------------------" << std::endl;

	delete tab[0];
	delete tab[1];
	delete tab[2];
	delete tab[3];

	return (0);
}
