// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Logger.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/04 16:15:18 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/04 16:15:20 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Logger.hpp"
#include <fstream>
#include <ctime>

Logger::Logger(void) {}

Logger::Logger(std::string file_name) {
	this->file_name = file_name;
	std::cout << "NEW CLASS OF Logger was create  " << "file_name : " << 
			this->file_name << std::endl;
}

Logger::~Logger(void) {
	std::cout << "NU VSE CLASU PIZDEC" << std::endl;
}

std::string Logger::makeLogEntry(std::string const & message) {

	struct tm * timeinfo;
	char buffer [80];
	time_t timer = time(&timer);
	timeinfo = localtime (&timer);
	strftime (buffer, 80, "%Y%m%d_%H%M%S", timeinfo);
	std::string res(buffer);
	res += " " + message;
	return res;
}

void Logger::logToConsole(std::string const & message) {
	std::string res = makeLogEntry(message);
	std::cout << res << std::endl;
}

void Logger::logToFile(std::string const & message) {
	std::string lala = makeLogEntry(message);
 	std::ofstream res;
 	res.open(this->file_name);
	if (!res.is_open())
	{
		std::cout << "Couldn't write to the file." << std::endl;
		exit(1);
	}
	std::cout << "FILE " << this->file_name << " was created " << std::endl;
	res << lala;
	res.close();
}


void	Logger::log(std::string const &dest, std::string const & message) {
	void (Logger::*sraka[2])(std::string const & message) = { &Logger::logToConsole, &Logger::logToFile};
	std::string names[2] = {"logToConsole", "logToFile"};
	for(int i = 0; i < 2; i++)
		if (names[i] == dest)
			(this->*sraka[i])(message);
}
