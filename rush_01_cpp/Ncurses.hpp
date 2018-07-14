// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Ncurses.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/14 21:19:41 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/14 21:19:44 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef NCURSES_HPP
#define NCURSES_HPP

# include "IMonitorDisplay.hpp"
# include <ncurses.h>
# include <iostream>
# include <unistd.h>
# include "Cor.hpp"

class Ncurses : public IMonitorDisplay
{
	private:
		Cor::sys_data_t & sys_data;
		bool start;
		int index;
	public:
		Ncurses();
		Ncurses(Cor::sys_data_t & sys_data);
		Ncurses ( Ncurses const & src );
		Ncurses &operator=( Ncurses const & src);
		~Ncurses();
		void loop(void);
		void onColor();
		bool getStart() const ;
		Cor::sys_data_t &getSys_data() const ;

		void draw_line(int & i);		
		void set_info(int & i, std::string const & res);
		void exit_a();

		void osInfo(int & i);
		void huInfo(int & i);
		void dtInfo(int & i);
		void piInfo(int & i);
		void cpuInfo(int & i);
		void rmInfo(int & i);
		void vmInfo(int & i);
		void hmInfo(int & i);
		void netInfo(int & i);
		void uniInfo(int & i);
};

#endif
