// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/03 21:20:42 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/03 21:20:44 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main(void)
{
	{
		Weapon club = Weapon("AK 47");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("M16");
		bob.attack();
	}
	{
		Weapon club = Weapon("vibrator");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("costyl");
		jim.attack();
	}
	return (0);
}