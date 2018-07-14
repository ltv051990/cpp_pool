// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Ncurses.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/14 21:19:19 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/14 21:19:25 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Ncurses.hpp"

Ncurses::Ncurses(Cor::sys_data_t & sys_data) : sys_data(sys_data) {
	if (!(initscr())) {
		std::cout << "SORRY NCURSES PROBLEM!!! PLEASE USE TOP" << std::endl;
		exit(0);
	}
	noecho();
	curs_set(0);
	keypad(stdscr, TRUE);
	refresh();
	start_color();
	onColor();
	bkgd(COLOR_PAIR(17));
	start = false;
	index = 0;
}

Ncurses & Ncurses::operator=( Ncurses const & src) {
	this->sys_data = getSys_data();
	this->start = src.getStart();
	return	*this;
}

Ncurses::Ncurses ( Ncurses const & src ): sys_data(src.getSys_data()) {
	*this = src;
}

bool	Ncurses::getStart() const { return this->start; }

Cor::sys_data_t &Ncurses::getSys_data() const { return sys_data; }

Ncurses::~Ncurses() {
	endwin();
}

void Ncurses::onColor() {
	init_pair(1,  COLOR_GREEN, COLOR_BLACK);
	init_pair(2,  COLOR_RED, COLOR_BLACK);
	init_pair(3,  COLOR_YELLOW, COLOR_BLACK);
	init_pair(4,  COLOR_BLUE, COLOR_BLACK);
	init_pair(14, COLOR_CYAN, COLOR_BLACK);
	init_pair(15, COLOR_WHITE, COLOR_BLACK);
	init_pair(17, COLOR_BLACK, COLOR_BLACK);
	init_pair(18, COLOR_CYAN, COLOR_BLACK);
}


void Ncurses::draw_line(int & i) {
	this->start = true;
	attron(COLOR_PAIR(2) | A_BOLD);
	mvprintw(i, 0 ,"%s", "_____________________________________________________");
	++i;
}

void Ncurses::set_info( int & i, std::string const & res ) {
	int x  = 25;
	attron(COLOR_PAIR(15));
	mvprintw(i, x, "%s         ", res.c_str());
	++i;
}

void Ncurses::exit_a(){
	endwin();
	exit(0);
}

void Ncurses::osInfo(int & i) {
	draw_line(i);

	attron(COLOR_PAIR(3) | A_BOLD);
	mvprintw(i, 0 ,"%s", " >>>>>>>>>>>>>>>        OS INFO       <<<<<<<<<<<<<< ");
	++i;

	attron(COLOR_PAIR(4) | A_BOLD);
	mvprintw(i, 0, "%s", "Sysname");
	set_info(i, this->sys_data.sysname);

	attron(COLOR_PAIR(4));
	mvprintw(i,0,"%s", "Release");
	set_info(i, this->sys_data.release);

	attron(COLOR_PAIR(4));
	mvprintw(i,0,"%s", "Version");
	set_info(i, this->sys_data.version);

	attron(COLOR_PAIR(4));
	mvprintw(i,0,"%s", "Machine");
	set_info(i, this->sys_data.machine);
}

void Ncurses::huInfo(int & i) {
	draw_line(i);

	attron(COLOR_PAIR(3) | A_BOLD);
	mvprintw(i, 0 ,"%s", " >>>>>>>>>>>>>>  HOSTNAME && USERNAME  <<<<<<<<<<<<<");
	++i;

	attron(COLOR_PAIR(4));
	mvprintw(i,0,"%s", "Hostname");
	set_info(i, this->sys_data.hostname);

	attron(COLOR_PAIR(4));
	mvprintw(i,0,"%s", "Username");
	set_info(i, this->sys_data.username);
}

void Ncurses::dtInfo(int & i) {
	draw_line(i);

	attron(COLOR_PAIR(3) | A_BOLD);
	mvprintw(i, 0 ,"%s", " >>>>>>>>>>>>>>>     DATE && TIME     <<<<<<<<<<<<<<");
	++i;

	attron(COLOR_PAIR(4));
	mvprintw(i,0,"%s", "Date");
	set_info(i, this->sys_data.date);

	attron(COLOR_PAIR(4));
	mvprintw(i,0,"%s", "Time");
	set_info(i, this->sys_data.time);
}

void Ncurses::piInfo(int & i) {
	draw_line(i);

	attron(COLOR_PAIR(3) | A_BOLD);
	mvprintw(i, 0 ,"%s", " >>>>>>>>>>>>>>>        PROCESS       <<<<<<<<<<<<<<");
	++i;

	attron(COLOR_PAIR(4));
	mvprintw(i,0,"%s", "Total process");
	set_info(i, this->sys_data.proc_total);

	attron(COLOR_PAIR(4));
	mvprintw(i,0,"%s", "Run process");
	set_info(i, this->sys_data.proc_run);

	attron(COLOR_PAIR(4));
	mvprintw(i,0,"%s", "Slepp process");
	set_info(i, this->sys_data.proc_sleep);

	attron(COLOR_PAIR(4));
	mvprintw(i,0,"%s", "Threads");
	set_info(i, this->sys_data.threads);
}

void Ncurses::cpuInfo(int & i) {
	draw_line(i);

	attron(COLOR_PAIR(3) | A_BOLD);
	mvprintw(i, 0 ,"%s", " >>>>>>>>>>>>>>>         CPU          <<<<<<<<<<<<<");
	++i;

	attron(COLOR_PAIR(4));
	mvprintw(i,0,"%s", "User");
	set_info(i, this->sys_data.cpuUser);

	attron(COLOR_PAIR(4));
	mvprintw(i,0,"%s", "System");
	set_info(i, this->sys_data.cpuSys);

	attron(COLOR_PAIR(4));
	mvprintw(i,0,"%s", "Idle");
	set_info(i, this->sys_data.cpuIdle);
}

void	Ncurses::rmInfo(int & i) {
	draw_line(i);

	attron(COLOR_PAIR(3) | A_BOLD);
	mvprintw(i, 0 ,"%s", " >>>>>>>>>>>>>>>        RAM MEM       <<<<<<<<<<<<<<");
	++i;

	attron(COLOR_PAIR(4));
	mvprintw(i,0,"%s", "PhysMem used");
	set_info(i, this->sys_data.physMemUs);

	attron(COLOR_PAIR(4));
	mvprintw(i,0,"%s", "PhysMem unused");
	set_info(i, this->sys_data.physMemUnus);
}

void	Ncurses::vmInfo(int & i) {
	draw_line(i);

	attron(COLOR_PAIR(3) | A_BOLD);
	mvprintw(i, 0 ,"%s", " >>>>>>>>>>>>>>>       VIRT MEM       <<<<<<<<<<<<<<");
	++i;

	attron(COLOR_PAIR(4));
	mvprintw(i,0,"%s", "VM vsize");
	set_info(i, this->sys_data.virtMemSize);

	attron(COLOR_PAIR(4));
	mvprintw(i,0,"%s", "VM framework vsize");
	set_info(i, this->sys_data.virtMemFramSize);
}

void Ncurses::hmInfo(int & i) {
	draw_line(i);

	attron(COLOR_PAIR(3) | A_BOLD);
	mvprintw(i, 0 ,"%s", " >>>>>>>>>>>>>>>       HARD MEM       <<<<<<<<<<<<<<");
	++i;

	attron(COLOR_PAIR(4));
	mvprintw(i,0,"%s", "Disks read");
	set_info(i, this->sys_data.disksRead);

	attron(COLOR_PAIR(4));
	mvprintw(i,0,"%s", "Disks written");
	set_info(i, this->sys_data.disksWritten);
}

void Ncurses::netInfo(int & i) {
	draw_line(i);

	attron(COLOR_PAIR(3) | A_BOLD);
	mvprintw(i, 0 ,"%s", " >>>>>>>>>>>>>>>       NETWORKS       <<<<<<<<<<<<<<");
	++i;

	attron(COLOR_PAIR(4));
	mvprintw(i,0,"%s", "Networks: packets in");
	set_info(i, this->sys_data.packets_in);

	attron(COLOR_PAIR(4));
	mvprintw(i,0,"%s", "Networks: packets out");
	set_info(i, this->sys_data.packets_out);
}

void Ncurses::uniInfo(int & i) {
	draw_line(i);

	attron(COLOR_PAIR(3) | A_BOLD);
	mvprintw(i, 0 ,"%s", " >>>>>>>>>>>>>>>       AUTHORS       <<<<<<<<<<<<<<<");
	++i;
	attron(COLOR_PAIR(1));
	mvprintw(i,0,"%s", "pgritsen");
	++i;
	attron(COLOR_PAIR(18));
	mvprintw(i,0,"%s", "tlutsyk");
	++i;
}

void Ncurses::loop(void) {
	int i = 0;
	int key = 0;

	timeout(0);
	key = getch();
	if (key == 27)
		exit_a();

	if (this->sys_data.all_mode) {
			osInfo(i);
			huInfo(i);
			dtInfo(i);
			piInfo(i);
			cpuInfo(i);
			rmInfo(i);
			vmInfo(i);
			hmInfo(i);
			netInfo(i);
	}
	else {
		if (sys_data.flags.find("os") != std::string::npos)
			osInfo(i);
		if (sys_data.flags.find("hu") != std::string::npos)
			huInfo(i);
		if (sys_data.flags.find("dt") != std::string::npos)
			dtInfo(i);
		if (sys_data.flags.find("pi") != std::string::npos)
			piInfo(i);
		if (sys_data.flags.find("cpu") != std::string::npos)
			cpuInfo(i);
		if (sys_data.flags.find("rm") != std::string::npos)
			rmInfo(i);
		if (sys_data.flags.find("vm") != std::string::npos)
			vmInfo(i);
		if (sys_data.flags.find("hm") != std::string::npos)
			hmInfo(i);
		if (sys_data.flags.find("net") != std::string::npos)
			netInfo(i);
		if (sys_data.flags.find("uni") != std::string::npos)
			uniInfo(i);
	}

	if (this->start) {
		draw_line(i);
		refresh();
		usleep(350000);
	}
	else
		exit_a();
}
