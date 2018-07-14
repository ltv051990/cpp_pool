// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Logger.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/04 16:15:28 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/04 16:15:30 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef LOGGER_HPP
#define LOGGER_HPP
#include <iostream>
class Logger
{
	private:
		void logToConsole(std::string const & message);
		void logToFile(std::string const & message);
		static std::string makeLogEntry(std::string const & message);
		std::string file_name;
	public:
		Logger(void);
		Logger(std::string file_name);
		~Logger(void);
		void log(std::string const &dest, std::string const & message);
};

#endif
