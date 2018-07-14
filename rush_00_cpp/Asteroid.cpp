// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Asteroid.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/08 15:12:21 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/08 15:12:23 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Asteroid.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

# define WIDTH 100
#define HEIGHT 48

Asteroid::Asteroid(){
	this->x = ((rand()) * std::time(nullptr)) % 99;
	this->y = ((rand()) * std::time(nullptr)) % 3;
}

Asteroid::Asteroid(Asteroid const & src){
	*this = src;
}

Asteroid::~Asteroid(void){};

Asteroid & Asteroid::operator=(Asteroid const & src)
{
	this->x = src.x;
	this->y = src.y;
	return *this;
}

bool Asteroid::asteroid_move()
{
	if (y < HEIGHT - 1) {
		y += 1;
	return true;
	}
	return false;
}

int Asteroid::getX( void ) const {
	return this->x;
}

int Asteroid::getY( void ) const {
	return this->y;
}
