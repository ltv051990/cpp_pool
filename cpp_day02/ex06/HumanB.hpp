// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   HumanB.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/03 21:21:09 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/03 21:21:12 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "Weapon.hpp"
#include <string>

class HumanB
{
		std::string name;
		Weapon *weapon;
	public:
		HumanB(std::string name);
		~HumanB(void);
		void setWeapon (Weapon &weapon);
		void attack (void);
};

#endif
