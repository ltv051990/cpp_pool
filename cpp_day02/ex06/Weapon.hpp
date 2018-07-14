// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Weapon.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/03 21:20:27 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/03 21:20:29 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <string>

class Weapon
{
		std::string type;
	public:
		Weapon( std::string type );
		~Weapon(void);
		void	setType (std::string type);
		const std::string &getType( void );
};

#endif

/*
*** My boss is a dick
*/