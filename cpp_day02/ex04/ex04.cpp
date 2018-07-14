// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ex04.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/03 18:31:28 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/04 23:12:32 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

/*
*** My boss is a dick
*/

#include <iostream>

int main(void) {
	std::string blabla = "HI THIS IS BRIAN";
	std::string *uk = &blabla;
	std::string &req = blabla;

	std::cout << uk << std::endl;
	std::cout << &req << std::endl;

	return (0);
}
