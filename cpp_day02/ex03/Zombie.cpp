// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Zombie.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/03 12:45:58 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/03 12:46:00 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Zombie.hpp"
#include <ctime>

int Zombie::random = std::time(nullptr) % 10;

Zombie::Zombie(void) {
	this->type = "dead_man";
	this->name = randomName();
	return ;
}

std::string		Zombie::randomName(void) {
	std::string	const names[] = { "PUTIN", "BOBBY", "STRAPONY", "ANTOSHA", "LOSHOK",
							"PUPSIK", "VASIA", "TOCHA", "KOKS", "MUDAK" };
	std::string name = names[(random * 33) % 10];
	random++;
	return (name);
}

Zombie::~Zombie(void) {
	std::cout << "FUCK!!! YOU KILL ZOMBIE : " << this->name << std::endl; 
	return ;
}

void	Zombie::announce(void) {
	std::cout << name << " : "<< this->type << " say " << "Braiiiiiiiinnnssss..." << std::endl;
	return ;
}
