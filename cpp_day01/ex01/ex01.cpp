// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ex01.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/03 11:39:13 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/03 11:39:14 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

void	memoryLeak(void)
{
	std::string* panthere = new std::string("String panthere");
	std::cout << *panthere << std::endl;
	delete panthere;
}
