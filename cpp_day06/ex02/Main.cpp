// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/11 15:46:22 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/11 15:46:26 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

class Base { public: virtual ~Base() {} };
class A: public Base {};
class B: public Base {};
class C: public Base {};

Base *generate( void ) {
	srand(clock());
	int random  = (rand() * std::time(nullptr) % 3);
	if (random == 1) {
		std::cout << "Class B was born!!!" << std::endl;
		B *b = new B;
		return (b);
	}
	else if (random == 2) {
		std::cout << "Class C was born!!!" << std::endl;
		C *c = new C;
		return (c);
	}
	else if (random == 0) 
		std::cout << "Class A was born!!!" << std::endl;
	A *a = new A;
	return (a);
}

void identify_from_pointer( Base * p ) {
	if (dynamic_cast<A*>(p))
		std::cout << "It is an A pointer!!!" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "It is an B pointer!!!" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "It is an C pointer!!!" << std::endl;
	else
		std::cout << "User is a dick or an idiot!!!" << std::endl;

}

void identify_from_reference( Base & p) {
	try {
		A &a = dynamic_cast<A &>(p);
		if (sizeof(a) > 0)
			std::cout << "It's an A reference!" << std::endl;
	}
	catch (std::bad_cast &bc ) {
//		std::cout << "User is a dick or an idiot!!! It is not a A class" << std::endl;
	}
	try {
		B &b = dynamic_cast<B &>(p);
		if (sizeof(b) > 0)
			std::cout << "It's B reference!" << std::endl;
	}
	catch (std::bad_cast &bc ) {
//		std::cout << "User is a dick or an idiot!!! It is not a B class" << std::endl;
	}
	try {
		C &c = dynamic_cast<C &>(p);
		if (sizeof(c) > 0)
			std::cout << "It's an C reference!" << std::endl;
	}
	catch (std::bad_cast &bc ) {
//		std::cout << "User is a dick or an idiot!!! It is not a C class" << std::endl;
	}
}

int main ( void ) {
	Base *base = generate();
	identify_from_pointer(base);
	identify_from_reference(*base);
	delete base;
	return 0;
}
