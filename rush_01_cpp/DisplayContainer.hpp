/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DisplayContainer.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:28:02 by pgritsen          #+#    #+#             */
/*   Updated: 2018/04/15 11:11:27 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAYCONTAINER_HPP
# define DISPLAYCONTAINER_HPP

#include <vector>
#include "Cor.hpp"
#include "IMonitorDisplay.hpp"
#include "AMonitorModule.hpp"
#include "CpuLoadModule.hpp"
#include "ProcessesModule.hpp"
#include "ClockModule.hpp"
#include "HardMemModule.hpp"
#include "RAMMemModule.hpp"
#include "NetworkModule.hpp"
#include "UserDataModule.hpp"
#include "OSInfoModule.hpp"
#include "VirtMemModule.hpp"
#include "UnicornModule.hpp"

class DisplayContainer : public IMonitorDisplay
{
	public:
		DisplayContainer(Cor::sys_data_t & sys_data);
		DisplayContainer(DisplayContainer const & copya);
		virtual ~DisplayContainer(void);

		DisplayContainer	&operator = (DisplayContainer const & elem);

		void	loop(void);

	private:
		DisplayContainer(void);

		void		_deleteWindow(int window_id);

		std::vector<AMonitorModule *>	_modules;
		Cor::sys_data_t					& sys_data;
};

#endif
