// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Human.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/03 19:06:37 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/03 19:06:40 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef HUMAN_HPP
#define HUMAN_HPP
#include "Brain.hpp"

class Human
{
		const Brain nuts;

	public:
		Human(void);
		~Human(void);
		std::string identify( void ) const;
		const Brain	&getBrain(void) const;
};

#endif
