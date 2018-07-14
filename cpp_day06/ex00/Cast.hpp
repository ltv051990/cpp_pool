// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Cast.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/10 21:16:24 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/10 21:16:26 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CAST_HPP
#define CAST_HPP
#include <iostream>
#include <iomanip>
#include <sstream>
#include <climits>
#include <cfloat>
#include <cmath>

class Cast
{
	private:
		std::string read;
		double nb;
	public:
		Cast();
		Cast(std::string const & tmp);
		Cast(Cast const & src);
		~Cast();
		Cast &operator=(Cast const &src);

		std::string getArgv() const ;
 		void setArgv(std::string const & name);

		void start_conversion();
		void write_stream() const ;
		void conversion_char() const ;
	  	void conversion_int() const ;
	  	void conversion_float() const ;
	  	void conversion_double() const ;
};

#endif
