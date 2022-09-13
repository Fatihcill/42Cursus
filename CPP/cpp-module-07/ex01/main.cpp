/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:37:01 by fcil              #+#    #+#             */
/*   Updated: 2022/09/13 13:39:45 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void    print(const int &n)
{
    std::cout << n << " ";
}

void print2(const std::string &s)
{
    std::cout << s + " ";
}

int main()
{
    int array[5] = {0, 1, 9, 0, 7};
    iter(array, 5, print);
    std::cout << std::endl;
    std::string arr[2] = {"test1", "test2"};
    iter(arr, 2, print2);
}
