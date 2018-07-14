// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ZombieHorde.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/03 17:07:11 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/03 17:07:13 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ZombieHorde.hpp"
#include <exception>

ZombieHorde::ZombieHorde(void) {
	return ;
}

ZombieHorde::ZombieHorde(int nb) {
	try
	{
		this->ukaz = new Zombie[nb];
	}
	catch (std::exception& e)
	{
		std::cout << "FUCK!!!" << e.what() << std::endl;
	}
	this->nb = nb;
	return ;
}

ZombieHorde::~ZombieHorde(void) {
	delete [] this->ukaz;
	std::cout << "ZombieHorde delete and all memory was freed" << std::endl;
	return ;
}

void ZombieHorde::announce(void) {
	for (int i = 0; i < this->nb; i++)
		ukaz[i].announce();
	return ;
}