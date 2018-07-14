// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Array.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/12 12:22:18 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/12 12:22:19 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>

template <typename T>
class Array
{
	private:
		unsigned int _size;
		T *array;

	public:
		Array<T>(): _size(0) { array = new T[0]; };
		
		Array<T>( unsigned int size ): _size(size) {
			array = new T[size]();
		}
		
		Array<T>(Array<T> const & src) {
			_size = src.size();
			array = new T[src.size()]();
			for (unsigned int i = 0; i < _size; i++)
				array[i] = src[i];
		}

		~Array<T>(){
			delete[] array;
		}

		Array<T> operator=(Array<T> const & src) {
			_size = src.size();
			delete[] array;
			array = new T[src.size()]();
			for (unsigned int i = 0; i < _size; i++)
				array[i] = src[i];
			return *this;
		}

		T &operator[]( unsigned int i) const
		{
			if (i >= _size)
				throw std::exception();
			return array[i];
		}

		unsigned int size ( void ) const { return _size; }
};

#endif
