/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSInfoModule.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 20:42:50 by pgritsen          #+#    #+#             */
/*   Updated: 2018/04/14 23:41:12 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OSInfoModule.hpp"

OSInfoModule::OSInfoModule(Cor::sys_data_t	& sys_data) : AMonitorModule("OS Infromation", 200, 140, sys_data) {}

void			OSInfoModule::draw(void) const
{
	this->fillBackGround(0xFFFFFF);
	this->drawString(this->sys_data.sysname.c_str(), 60 - this->sys_data.sysname.length() * 2, 10, false, true, 0xFF0000);
	this->drawString(this->sys_data.release.c_str(), 67 - this->sys_data.release.length() * 2, 45, false, true, 0x0000FF);
	this->drawString(this->sys_data.machine.c_str(), 60 - this->sys_data.machine.length() * 2, 80, false, true, 0x0);
	SDL_UpdateWindowSurface(this->_win_ptr);
}
