// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/12 12:21:02 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/12 12:21:04 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Array.hpp"
#include <iomanip>

int main( void )
{
	unsigned int ia = 6;

	std::cout << ">>>>>>>>>> initial object <<<<<<<<<<" << std::endl << std::endl;
	Array<double> a(6);
	for(unsigned int i = 0; i < ia; i++) 
		a[i] = (double)i;

	std::cout << ">>>>>>>>>> print values <<<<<<<<<<" << std::endl << std::endl;

	for (unsigned int i = 0; i < a.size(); i++)
	 	std::cout << "array[" << std::fixed << std::setprecision(1) << i << "] = " << a[i] << std::endl;

	std::cout << ">>>>>>>>>> try and catch <<<<<<<<<<" << std::endl << std::endl;

	try
	{
		a[666] = 123;
		std::cout << "OK" << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << " >>>>>>>>> ERROR BAD INDEX <<<<<<<<<" << std::endl << std::endl;
	}

	std::cout << ">>>>>>>>>> cope construtor <<<<<<<<<<" << std::endl << std::endl;

	Array<double> b(a);
	for (unsigned int i = 0; i < b.size(); i++)
	 	std::cout << "array[" << std::fixed << std::setprecision(1) << i << "] = " << b[i] << std::endl;
}


















































/*

	// for (i = 0; i < array.size(); i++)
	// 	std::cout << "array[" << i << "] = " << array[i] << std::endl;
// 	std::cout << "- change values -" << std::endl;
// 	std::cout << "array[2] = 4" << std::endl;
// 	array[2] = 4;
// 	std::cout << "array[3] = 2" << std::endl;
// 	array[3] = 2;
// 	std::cout << "array[6] = 1 ";
// 	try
// 	{
// 		array[6] = 1;
// 		std::cout << "OK" << std::endl;
// 	}
// 	catch(std::exception &e)
// 	{
// 		std::cout << "ERROR" << std::endl;
// 	}

// 	std::cout << "-- testing copying --" << std::endl;
// 	std::cout << "-- Copying through copy constructor --" << std::endl;
// 	Array<int> copy = Array<int>(array);
// 	for (i = 0; i < copy.size(); i++)
// 		std::cout << "copy[" << i << "] = " << copy[i] << std::endl;
// 	std::cout << "- change values -" << std::endl;
// 	std::cout << "copy[3] = 424242" << std::endl;
// 	copy[3] = 424242;
// 	std::cout << "- initial array -" << std::endl;
// 	for (i = 0; i < array.size(); i++)
// 		std::cout << "array[" << i << "] = " << array[i] << std::endl;
// 	std::cout << "- copied and altered array -" << std::endl;
// 	for (i = 0; i < copy.size(); i++)
// 		std::cout << "copy[" << i << "] = " << copy[i] << std::endl;

// 	std::cout << "-- Copying through assignment --" << std::endl;
// 	copy = array;
// 	for (i = 0; i < copy.size(); i++)
// 		std::cout << "copy[" << i << "] = " << copy[i] << std::endl;
// 	std::cout << "copy[3] = 424242" << std::endl;
// 	std::cout << "- change values -" << std::endl;
// 	copy[3] = 424242;
// 	std::cout << "- initial array -" << std::endl;
// 	for (i = 0; i < array.size(); i++)
// 		std::cout << "array[" << i << "] = " << array[i] << std::endl;
// 	std::cout << "- copied and altered array -" << std::endl;
// 	for (i = 0; i < copy.size(); i++)
// 		std::cout << "copy[" << i << "] = " << copy[i] << std::endl;
}*/