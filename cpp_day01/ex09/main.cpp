// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/04 16:15:06 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/04 16:15:08 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Logger.hpp"

int main(void)
{
	Logger sh("pizdez");
	sh.log("logToConsole", "BLIA!!! I FUCK C++");
	sh.log("logToFile", "SUKA!!! I FUCK C++");
	return 0;
}