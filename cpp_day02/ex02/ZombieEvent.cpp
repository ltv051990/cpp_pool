// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ZombieEvent.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/03 12:46:36 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/03 12:46:38 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ZombieEvent.hpp"
#include <ctime>

ZombieEvent::ZombieEvent(void) {
	return ;
}

ZombieEvent::~ZombieEvent(void) {
	return ;
}

void	ZombieEvent::setZombieType(std::string type) {
	this->type = type;
}

Zombie *ZombieEvent::newZombie(std::string name) {
	Zombie *badGay = new Zombie(name); 
	return (badGay);
}

void	ZombieEvent::randomChump(void) {
	std::string	const names[] = { "PUTIN", "BOBBY", "STRAPONY", "ANTOSHA", "LOSHOK",
							"PUPSIK", "VASIA", "TOCHA", "KOKS", "MUDAK" };
	std::string name = names[std::time(nullptr) % 10];
	Zombie vasyl(name, this->type);
	vasyl.announce();
}
