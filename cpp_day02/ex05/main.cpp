// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/03 19:04:44 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/03 19:04:46 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Human.hpp"

int main(void) {
	Human bob;

	std::cout << bob.identify() << std::endl;
	std::cout << bob.getBrain().identify() << std::endl;
	return (0);
}
