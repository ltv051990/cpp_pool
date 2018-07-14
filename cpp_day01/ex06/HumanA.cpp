// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   HumanA.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/03 21:20:54 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/03 21:20:58 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon):weapon(weapon) {
	this->name = name;
//	this->weapon = &weapon;
	return ;
}

HumanA::~HumanA(void) {}

void	HumanA::attack ( void ) {
	std::cout << this->name << " attack with his " << this->weapon.getType() 
			<< std::endl;
	return ;
}
