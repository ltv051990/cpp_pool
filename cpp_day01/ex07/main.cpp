// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/04 09:40:50 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/04 09:40:52 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>

/*
*** DON'T FORGET: MY BOSS IS A DICK
*/

int main(int argc, char **argv)
{
	if (argc != 4 || !(argv[1][0]) || !(argv[2][0]) || !(argv[3][0])) {
		std::cout << "Bad arguments !!! file s1 s2" << std::endl;
		return 0;
	}
	std::string replace(argv[2]);
	std::string what(argv[3]);
	size_t index = 0;
 	std::ofstream res;
	std::ifstream infile;
	std::stringstream buf;
	std::string tmp;
	infile.open (argv[1]);
	if (infile.fail()) {
		std::cout << "ERROR!!! COULD NOT OPEN A FILE!!!" << std::endl;
		exit(1);
	}
	if (!infile.is_open())
	{
		std::cout << "FUCK YOURSELF!!!" << std::endl;
		exit(1);
	}
	buf << infile.rdbuf();
	tmp  = buf.str();
	if (!tmp.length())
	{
		std::cout << "A TUT U MENE SRAKA Xa Xa" << std::endl;
		exit(0);
	}
	while ((index = tmp.find(replace, index)) != std::string::npos)
	{
			tmp.replace(index, replace.length(), what);
			index += what.length();
	}
 	infile.close();
 	std::string f(argv[1]);
	res.open(f + ".replace");
	if (!res.is_open())
	{
		std::cout << "Couldn't write to the file." << std::endl;
		exit(1);
	}
	res << tmp;
	res.close();
	return 0;
}

/* My boss is a dick
// 	while(!infile.eof()) // To get you all the lines.
//     {
// 		getline(infile, STRING); // Saves the line in STRING.
// 		if (STRING.length() != 0)
// 			tmp += (STRING + "\n");
// 		STRING.clear();
// //       	std::cout << STRING << std::endl;; // Prints our STRING.
//     }
*/