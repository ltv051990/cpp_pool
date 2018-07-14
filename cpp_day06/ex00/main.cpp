// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/10 10:26:21 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/10 10:26:23 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Cast.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "I think a user is an idiot!!! Are you really stuped? Only one argument!!!" << std::endl;
		return -1;
	}
	Cast a((std::string(argv[1])));
	a.start_conversion();
	return 0;
}
