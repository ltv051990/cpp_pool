// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Cor.cpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/14 15:24:36 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/14 15:24:38 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Cor.hpp"
#include "DisplayContainer.hpp"
#include "Ncurses.hpp"
#include <sys/utsname.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sstream>

Cor::Cor(){
	this->grafic = 0;
	this->start = 1;
}

Cor::Cor(bool grafic, bool mode, std::string const & flags): grafic(grafic){
	sys_data.all_mode = mode;
	sys_data.flags = flags;
	this->start = 1;
}

Cor::Cor(Cor const & src) {
	*this = src;
}

Cor &Cor::operator=(Cor const & src) {
	this->sys_data = src.getSys_data();
	this->start = src.getStart();
	this->grafic = src.getGrafic();
	return *this;
}

Cor::sys_data_t Cor::getSys_data() const { return this->sys_data; }
bool Cor::getStart() const { return this->start; }
bool Cor::getGrafic() const { return this->grafic; };

Cor::~Cor(){}

void	Cor::loop(){
	if (grafic)
	{
		DisplayContainer	prog(this->sys_data);
		unsigned			last_time = SDL_GetTicks();

		get_info();
		while (1)
		{
			if (SDL_GetTicks() - last_time > 1000)
			{
				get_info();
				last_time = SDL_GetTicks();
			}
			prog.loop();
		}
	}
	else
	{
		Ncurses text(this->sys_data);
		while (1) {
			get_info();
			text.loop();
		}
	}
}

void Cor::get_info () {
	if (start) {
		getOsMod();
		getHostMod();
	}

	std::stringstream    buf;
	FILE * fpIn = popen("/usr/bin/top -l 1 -n 0", "r");
	if (fpIn)
	{
		char arr[1024];
		while(fgets(arr, sizeof(arr), fpIn) != NULL)
			buf << arr;
		pclose(fpIn);
		buf << arr;
	}
	std::string tmp;
	while (std::getline(buf, tmp)) {
		if(tmp.find("Proc") != std::string::npos)
			getProcMod( tmp );
		else if (tmp.find("2018/04") != std::string::npos)
			getDaTiMod( tmp );
		else if (tmp.find("CPU") != std::string::npos)
			getCpuMod( tmp );
		else if (tmp.find("PhysMem") != std::string::npos)
			getRamMod ( tmp );
		else if (tmp.find("VM") != std::string::npos)
			getVmMod ( tmp );
		else if (tmp.find("Disks") != std::string::npos)
			getHmMod( tmp );
		else if (tmp.find("Networks") != std::string::npos)
			getNetMod( tmp );
	}
	start = 0;
}

void Cor::getOsMod () {
 	struct utsname name;

 	uname(&name);
	sys_data.sysname = name.sysname;
	sys_data.release = name.release;
	sys_data.version = name.version;
	sys_data.version.resize(28);
	sys_data.machine = name.machine;
}

void Cor::getHostMod () {
	char hostn[100];
	char usern[100];
	gethostname(hostn, 100);
	getlogin_r(usern, 100);
	sys_data.hostname = std::string(hostn);
	sys_data.username = std::string(usern);
}

void Cor::getDaTiMod ( std::string const & tmp ) {
	std::stringstream    buf;
	buf << tmp;
	std::getline(buf, sys_data.date, ' ');
	std::getline(buf, sys_data.time, ' ');
}

void Cor::getProcMod ( std::string const & tmp ) {
	std::stringstream    buf;
	buf << tmp;
	int i = 1;
	std::string tmp1;
	while(std::getline(buf, tmp1, ' ')) {
		if (i == 2)
			sys_data.proc_total = tmp1;
		else if (i == 4)
			sys_data.proc_run = tmp1;
		else if (i == 6)
			sys_data.proc_sleep = tmp1;
		else if (i == 8)
			sys_data.threads = tmp1;
		i++;
	}
}

void Cor::getCpuMod ( std::string const & tmp ) {
	std::stringstream    buf;
	buf << tmp;
	int i = 1;
	std::string tmp1;
	while(std::getline(buf, tmp1, ' ')) {
		if (i == 3)
			sys_data.cpuUser = tmp1;
		else if (i == 5)
			sys_data.cpuSys = tmp1;
		else if (i == 7)
			sys_data.cpuIdle = tmp1;
		i++;
	}
}

void Cor::getRamMod ( std::string const & tmp ) {
	std::stringstream    buf;
	buf << tmp;
	int i = 1;
	std::string tmp1;
	while(std::getline(buf, tmp1, ' ')) {
		if (i == 2)
			sys_data.physMemUs = tmp1;
		else if (i == 6)
			sys_data.physMemUnus = tmp1;
		i++;
	}
}

void Cor::getVmMod ( std::string const & tmp ) {
	std::stringstream    buf;
	buf << tmp;
	int i = 1;
	std::string tmp1;
	while(std::getline(buf, tmp1, ' ')) {
		if (i == 2)
			sys_data.virtMemSize = tmp1;
		else if (i == 4)
			sys_data.virtMemFramSize = tmp1;
		i++;
	}
}

void Cor::getHmMod ( std::string const & tmp ) {
	std::stringstream    buf;
	buf << tmp;
	int i = 1;
	std::string tmp1;
	while(std::getline(buf, tmp1, ' ')) {
		if (i == 2)
			sys_data.disksRead = tmp1;
		else if (i == 4)
			sys_data.disksWritten = tmp1;
		i++;
	}
}

void Cor::getNetMod ( std::string const & tmp ) {
	std::stringstream    buf;
	buf << tmp;
	int i = 1;
	std::string tmp1;
	while(std::getline(buf, tmp1, ' ')) {
		if (i == 3)
			sys_data.packets_in = tmp1;
		else if (i == 5)
			sys_data.packets_out = tmp1;
		i++;
	}
}
