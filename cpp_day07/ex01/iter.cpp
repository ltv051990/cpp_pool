// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   iter.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/11 21:13:04 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/11 21:13:05 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

template <typename T>
void	iter(T *array, unsigned int length, void (*f)(T&)) {
	for (unsigned int i = 0; i < length; i++)
		f(array[i]);
}

//void write_sqrt( int i ) { std::cout << "| int: " << i * 2 << "|" ; }

////////////////////////////////////////////////////////////////////////////////
////////////////////// EXAMPLE CHAR ////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// char write_char( char a ) { 
// 	std::cout << "| char: " << a << "|" ; 
// return a; }

template <typename T>
void write(T a) {
 	std::cout << "| ?: " << a << "|" ; 
}
////////////////////////////////////////////////////////////////////////////////
////////////////////// EXAMPLE FOR INT /////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


int main(void) {
	std::string tmp1[5]  = { "one", "two", "three", "four", "five"};
	int tmp[5] = { 5, 4, 3, 2, 1 };
	char text[] = "Bye, bye c++";

	std::cout << ">>>>>>>>> int part <<<<<<<<<<<" << std::endl;

	iter(tmp, 5, write);
	std::cout << std::endl << std::endl;

	std::cout << ">>>>>>>>> char part <<<<<<<<<<<" << std::endl;
	iter(text, sizeof(text) - 1, write);

	std::cout << std::endl << std::endl;


	std::cout << ">>>>>>>>> string part <<<<<<<<<<<" << std::endl;
	iter(tmp1, 5, write);

	std::cout << std::endl << std::endl << ">>>>>>>>>>>> HAPPY END <<<<<<<<<<<<<<" << std::endl;

	return 0;
}
