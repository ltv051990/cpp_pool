// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   HumanA.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/03 21:21:02 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/03 21:21:04 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef HUMANA_HPP
#define HUMANA_HPP
#include <string>
#include "Weapon.hpp"

	class HumanA
	{
		Weapon &weapon;
		std::string name;
		public:
			HumanA(std::string name, Weapon &weapon);
			~HumanA(void);
			void attack (void);
	};

#endif
