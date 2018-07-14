// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/03 09:56:57 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/03 09:56:58 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Pony.hpp"

void	ponyOntheHeap(void) {
	std::cout << "Start create horse on the heap" << std::endl;
	Pony* strapone = new Pony(300, "Losharyk", "Fast as a tortue!");
	strapone->ponyInfo();
	std::cout << "Start delete horse on the heap" << std::endl;
	delete strapone;
	std::cout << "Pony on the heap was deleted!" << std::endl;
}

void	ponyOntheStack(void) {
	std::cout << "Start create horse on the stack" << std::endl;
	Pony handony = Pony(150, "Serunchik", "Has a big dick!");
	handony.ponyInfo();
	std::cout << "Pony on the heap was deleted!" << std::endl;

}


int main(void){
	ponyOntheHeap();
	std::cout << std::endl << std::endl;
	ponyOntheStack();
	std::cout << std::endl;
	std::cout << "Pony strapony say good buy" << std::endl;
	return (0);
}