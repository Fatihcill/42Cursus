/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 10:30:02 by fcil              #+#    #+#             */
/*   Updated: 2022/08/08 11:21:14 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <iostream>

int	main()
{
	std::string	str;
	std::string	*stringPTR;

	str = "HI THIS IS BRAIN";
	stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "Address of str: " << &str << std::endl
	<< "Address of stringPTR: " << stringPTR << std::endl
	<< "Address of stringREF: " << &stringREF << std::endl << std::endl;

	std::cout << "Display by str: " << str << std::endl
	<< "Display by stringPTR: " << *stringPTR << std::endl
	<< "Display by stringREF: " << stringREF << std::endl;
}

/*
    int a = 10;
    int& ref = a; //ref a değişkenine referans olur.
    ref = 20; // a değişkeninin 20'ye eşitler.

    int b = 50;
    !! ref = b;  //referans atandığından başka bir değişkene referans olamaz
    !! ref = &b; //referans atandığından başka bir değişkene referans olamaz
────────────────────────────────────────────────────────────────────────────
    int increment(int& deger){
        deger++; //Fonksiyona verilen değişkenin kendisini değiştirir.
    }
    //Bu fonskiyonun pointerlı hali ise :
    int increment(int* deger){
        (*deger)++;
    }
*/