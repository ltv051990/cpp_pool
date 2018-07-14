// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ZombieHorde.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/03 17:07:17 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/03 17:07:20 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ZOMBIEHORDE_HPP
#define ZOMBIEHORDE_HPP
#include "Zombie.hpp"

class ZombieHorde
{
	Zombie *ukaz;
	int 	nb;	
	public:
		ZombieHorde(void);
		ZombieHorde(int nb);
		~ZombieHorde(void);
		void announce(void);
};

#endif
