// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Weapon.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/03 21:20:18 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/03 21:20:23 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
	this->type = type;
	return ;
}

Weapon::~Weapon(void) {
	return ;
}

void Weapon::setType(std::string type) {
	this->type = type;
}

const std::string &Weapon::getType( void ) {
	return this->type;
}
