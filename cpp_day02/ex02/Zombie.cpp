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

Zombie::Zombie(void) {
	return ;
}

Zombie::Zombie(std::string nam, std::string typ) {
	this->name = nam;
	this->type = typ;
	std::cout << "New ZOMBIE : " << name << " type of class : " << type << " was born " <<
		" and wont now to kill you"	<< std::endl;
	return ;
}

Zombie::Zombie(std::string nam) {
	this->name = nam;
	std::cout << "New ZOMBIE : " << name << " was born " <<
		" and wont now to kill you"	<< std::endl;
	return ;
}

Zombie::~Zombie(void) {
	std::cout << "FUCK!!! YOU KILL ZOMBIE :" << this->name << std::endl; 
	return ;
}

void	Zombie::announce(void) {
	std::cout << this->name << " : "<< this->type << " say " << "Braiiiiiiiinnnssss..." << std::endl;
	return ;
}
