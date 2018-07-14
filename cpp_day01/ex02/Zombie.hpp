// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Zombie.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/03 12:46:10 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/03 12:46:12 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>

class Zombie
{
	public:
		Zombie(void);
		Zombie(std::string name, std::string type);
		Zombie(std::string nam);
		~Zombie(void);

		void	announce(void);

		std::string name;
		std::string type;
};


#endif
