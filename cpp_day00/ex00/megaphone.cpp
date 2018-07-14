// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   megaphone.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/03/28 12:30:15 by tlutsyk           #+#    #+#             //
//   Updated: 2018/03/28 12:30:33 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
			return (0);
	}
	for (int line = 1; line < argc; line++)
		for (int letter = 0; argv[line][letter]; letter++)
			std::cout << char(toupper(argv[line][letter]));
	std::cout << std::endl;
	return (0);
}