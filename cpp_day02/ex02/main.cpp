// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/03 12:46:50 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/03 12:46:51 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ZombieEvent.hpp"

int main(void)
{
	//create new class ZombieEvent
	ZombieEvent openDay;
	ZombieEvent exams;
	// set a type variable in class ZombieEvent
	openDay.setZombieType("serun");
	exams.setZombieType("scikun");
	//call functons with random mame
	openDay.randomChump();
	//call functions that allocate memory on heap fot our Zombie
	Zombie *strelka = exams.newZombie("Mogula");
	strelka->announce();
	Zombie *belka = openDay.newZombie("sraka");
	belka->announce();
	//delete allocate with new memory
	delete strelka;
	delete belka;
	//create new zombie on the stack
	Zombie lol("vasia", "derskiy");
	lol.announce();
	return (0);
}
