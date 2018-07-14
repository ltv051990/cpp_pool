// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Pony.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/03 09:57:30 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/03 09:57:32 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Pony.hpp"

Pony::Pony(void) {
	return ;
}

Pony::Pony(int speed, std::string nick, std::string info) {
	this->max_speed = speed;
	this->nickname = nick;
	this->short_info = info;
	std::cout << "New pony " << nickname << " was born a few seconds ago!" << std::endl;
}

Pony::~Pony(void) {
	return ;
}

void	Pony::ponyInfo(void) {
	std::cout << std::endl;
	std::cout << "Name :       " << nickname << std::endl;
	std::cout << "Max speed  : " << max_speed << "km/h"<< std::endl;
	std::cout << "short_info : " << short_info << std::endl;
	std::cout << std::endl;
}
