// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Cast.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/10 21:16:19 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/10 21:16:21 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Cast.hpp"

Cast::Cast(){};
Cast::Cast(std::string const & argv) { this->read = argv; }
Cast::Cast(Cast const & src) { *this = src;}
Cast::~Cast(){}

Cast &Cast::operator=(Cast const & src) {
	this->read = src.getArgv();
	return *this;
}

void	Cast::start_conversion() {
	if (read.size() == 1 && isprint(read[0]) && (read[0] > 57|| read[0] < 48))
	{
		std::cout << "char: '" << char(read[0]) << "'" << std::endl;
		std::cout << "int " << static_cast<int>(read[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(read[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(read[0]) << ".0" << std::endl;
		return ;
	}
	else {
		if (read.size() > 1 && read.back() == 102 && read[read.size() - 2] != 'n')
			read.resize(read.size() - 1);
		std::stringstream tmp(read);
		tmp >> nb;
		if (tmp.fail() || !tmp.eof()) {
			write_stream();
			return ;
		}
		conversion_char() ;
		conversion_int() ;
		conversion_float() ;
		conversion_double() ;	
	}
}

void Cast::write_stream() const {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

	// ///////////////////////////////////////////////////////////////////////////
	// /////////////////////////// CAST TO CHAR   ////////////////////////////////
	// ///////////////////////////////////////////////////////////////////////////

void Cast::conversion_char() const {
	if (nb > CHAR_MAX || nb < 0)
		std::cout << "char: imposible" << std::endl;
	else if (isprint(nb))
		std::cout << "char: '" << static_cast<char>(nb) << "'" << std::endl;
	else
		std::cout << "char: non displayeble" << std::endl;
}

	// ///////////////////////////////////////////////////////////////////////////
	// /////////////////////////// CAST TO INT   /////////////////////////////////
	// ///////////////////////////////////////////////////////////////////////////

void Cast::conversion_int() const {
	if (read == "nan")
		std::cout << "int: imposible" << std::endl;
	else if (nb > INT_MAX || nb < INT_MIN)
		std::cout << "int: imposible" << std::endl;
	else
		std::cout << "int: "<< static_cast<int>(nb) << std::endl;
 }

	// ///////////////////////////////////////////////////////////////////////////
	// /////////////////////////// CAST TO FLOAT   ///////////////////////////////
	// ///////////////////////////////////////////////////////////////////////////

void Cast::conversion_float() const {
	if ((nb > FLT_MAX || nb < -FLT_MAX) && !std::isinf(nb))
		std::cout << "float: imposible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(nb) << "f" << std::endl;
}

	// ///////////////////////////////////////////////////////////////////////////
	// /////////////////////////// CAST TO DOUBLE   //////////////////////////////
	// ///////////////////////////////////////////////////////////////////////////

void Cast::conversion_double() const {
	std::cout << "double: " << std::fixed << std::setprecision(1) << nb << std::endl;
}

std::string Cast::getArgv() const { return this->read; }
void	Cast::setArgv(std::string const & name) {this->read = name; }