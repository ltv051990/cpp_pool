// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Human.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/03 19:06:26 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/03 19:06:28 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Human.hpp"

Human::Human(void) {
	return ;
}

Human::~Human(void) {
	return ;
}

std::string Human::identify( void ) const {
	return this->nuts.identify();
}

const Brain &Human::getBrain( void ) const {
	return this->nuts;
}
