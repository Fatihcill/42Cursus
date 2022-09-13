/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:42:33 by fcil              #+#    #+#             */
/*   Updated: 2022/09/13 14:09:06 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cstdlib>



template <typename T>
class Array
{
	private:
		unsigned int _len;
		T 			*_array;

	public:
		Array<T>()
		{
			_len = 0;
			_array = new T[_len];
		}

		Array<T>(unsigned int len)
		{
			_len = len;
			_array = new T[_len];
			for (unsigned int i = 0; i < len; i++)
			{
				_array[i] = 0;
			}
		}

		Array<T>(Array &arr)
		{
			_len = arr.size();
			_array = new T[_len];
			*this = arr;
			for (unsigned int i = 0; i < _len; i++)
			{
				_array[i] = arr[i];
			}
		}

		~Array<T>() 
		{
			if (this->_array)
				delete [] _array;
		}
		Array<T> &operator=(const Array &arr)
		{
			delete[] _array;
			_array = new T[arr.size()];
			_len = arr.size();
			for (unsigned int i = 0; i < _len; i++)
			{
				_array[i] = arr[i];
			}
			return (*this);
		}

		T & operator[](unsigned int i) const
		{
			if (i >= this->_len)
				throw (Array::outOfLimits());
			return (this->_array[i]);
		}

		unsigned int size() const
		{
			return this->_len;
		}

		class outOfLimits: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Index out of limits";
				}
		};
};
