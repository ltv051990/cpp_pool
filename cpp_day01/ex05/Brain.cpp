// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Brain.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/03 19:04:23 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/03 19:04:28 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Brain.hpp"
#include <sstream>
Brain::Brain(void) {
	return ;
}

Brain::~Brain(void) {
	return ;
}

std::string	Brain::identify(void) const {
	const void *location = static_cast<const void*>(this);
	std::stringstream ss;
	ss << location;
	return (ss.str());
}
