// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   HumanB.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/03 21:21:18 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/03 21:21:21 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) {
	this->name = name;
	return ;
}

HumanB::~HumanB(void) {
	return ;
}

void HumanB::attack (void) {
	std::cout << this->name << " attack with his " << this->weapon->getType() 
			<< std::endl;
	return ;
}

void	HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
	return ;
}
