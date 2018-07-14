// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Pony.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/03 09:57:40 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/03 09:57:43 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PONY_HPP
#define PONY_HPP
#include <iostream>

class Pony {
	public:
		Pony(void);
		Pony(int max_speed, std::string nickname, std::string short_info);
		~Pony(void);
		void	ponyInfo(void);
	
		int max_speed;
		std::string nickname;
		std::string short_info;
};

#endif
