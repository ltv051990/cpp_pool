// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Cor.hpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/14 15:24:42 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/14 15:24:49 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef COR_HPP
# define COR_HPP

# include "IMonitorDisplay.hpp"
# include <iostream>

class Cor: public IMonitorDisplay
{
	public:
		Cor(void);
		Cor(bool grafic, bool mode, std::string const & flags);
		Cor(Cor const & src);
		Cor &operator=( Cor const &src);
		virtual ~Cor(void);

		void getOsMod ( ) ;
		void getHostMod ( ) ;
		void getDaTiMod ( std::string const & tmp ) ;
		void getProcMod ( std::string const & tmp ) ;
		void getCpuMod ( std::string const & tmp ) ;
		void getRamMod ( std::string const & tmp ) ;
		void getVmMod ( std::string const & tmp ) ;
		void getHmMod ( std::string const & tmp ) ;
		void getNetMod ( std::string const & tmp ) ;

		typedef struct	sys_data_s
		{
			bool 		all_mode;
			std::string flags;

			// OS info mudule
			std::string sysname;
			std::string release;
			std::string version;
			std::string machine;
			// OS HOSTNAME && USERNAME
			std::string hostname;
			std::string username;
			// DATE && TIME
			std::string date;
			std::string time;
			// PROCESS
			std::string proc_total;
			std::string proc_run;
			std::string proc_sleep;
			std::string threads;
			// CPU
			std::string cpuUser;
			std::string cpuSys;
			std::string cpuIdle;
			// RAM MEM
			std::string physMemUs;
			std::string physMemUnus;
			// VIRT MEM
			std::string virtMemSize;
			std::string virtMemFramSize;
			// HARD MEM
			std::string disksRead;
			std::string disksWritten;
			// NETWORKS
			std::string packets_in;
			std::string packets_out;
		}				sys_data_t;

	void loop(void);
	void get_info(void);
	bool getStart() const;
	bool getGrafic() const ;
	sys_data_t getSys_data() const;

	private:
		bool		grafic;
		bool		start;
		sys_data_t	sys_data;
};

#endif
