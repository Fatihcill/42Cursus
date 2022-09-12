/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 00:27:48 by fcil              #+#    #+#             */
/*   Updated: 2022/09/13 00:52:00 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h>

typedef struct sData
{
	int X;
	int Y;
}Data;

uintptr_t	serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*deserialize(uintptr_t res)
{
	return (reinterpret_cast<Data *>(res));
}

int main()
{
	Data data = {0, 1};

	std::cout << serialize(&data) << " : adress-> " << &data <<std::endl;
	Data *ptr = deserialize(serialize(&data));

	std::cout << ptr << " | " << &data << std::endl;
	std::cout << (ptr == &data ? "The same pointer" : "pointers are differ") << std::endl;

	std::cout << "x: " << ptr->X << std::endl;
	std::cout << "y: " << ptr->Y << std::endl;
}

/*
const_cast<type> (expr) −
the const_cast does not cast between different types. Instead it changes the "const-ness" of the
expression. It can make something const what was not const before, or it can make something
volatile/changeable by getting rid of the const.

dynamic_cast<type> (expr) −
The dynamic_cast performs a runtime cast that verifies the validity of 
the cast. If the cast cannot be made, the cast fails and the expression evaluates to null.
A dynamic_cast performs casts on polymorphic types and can cast a A* pointer into a B* pointer 
only if the object being pointed to actually is a B object.

reinterpret_cast<type> (expr) −
Arguably one of the most powerful cast, the reinterpret_cast can convert from any built-in type to any other,
and from any pointer type to another pointer type. However, it cannot strip a variable's const-ness or
volatile-ness. It can however convert between built in data types and pointers without any regard to type 
safety or const-ness. This particular cast operator should be used only when absolutely necessary.

static_cast<type> (expr) −
The static_cast tells the compiler to attempt to convert between two different data types.
It will convert between built-in types, even when there is a loss of precision.
*/