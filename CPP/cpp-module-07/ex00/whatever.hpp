/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:14:15 by fcil              #+#    #+#             */
/*   Updated: 2022/09/13 13:32:11 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iostream"

template<class Type>
void    swap(Type &a, Type &b)
{
    Type temp;
    temp = a;
    a = b;
    b = temp;
}

template<class Type>
Type    min(Type &a, Type &b)
{
    return (a < b ? a : b);
}

template<class Type>
Type    max(Type &a, Type &b)
{
    return (a > b ? a : b);
}