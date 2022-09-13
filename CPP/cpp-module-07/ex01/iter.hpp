/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:37:46 by fcil              #+#    #+#             */
/*   Updated: 2022/09/13 13:38:43 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iostream"

template<typename Type>
void    iter(Type *array, size_t len, void(*f)(Type const &))
{
    for (size_t i = 0; i < len; i++)
        f(array[i]);
}
