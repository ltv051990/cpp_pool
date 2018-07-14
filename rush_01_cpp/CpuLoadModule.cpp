/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CpuLoadModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 19:54:11 by pgritsen          #+#    #+#             */
/*   Updated: 2018/04/14 23:03:15 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CpuLoadModule.hpp"

CpuLoadModule::CpuLoadModule(Cor::sys_data_t	& sys_data) : AMonitorModule("Cpu Load", 200, 80, sys_data) {}

void			CpuLoadModule::draw(void) const
{
	this->fillBackGround(0xFFFFFF);
	this->drawString("System :", 10, 10, false, false, 0x0);
	this->drawString(this->sys_data.cpuSys.c_str(), 160 - this->sys_data.cpuSys.length() * 2, 10, false, false, 0xFF0000);
	this->drawLine(5, 25, 195, 25, 0xC0C0C0);
	this->drawString("User :", 10, 35, false, false, 0x0);
	this->drawString(this->sys_data.cpuUser.c_str(), 160 - this->sys_data.cpuUser.length() * 2, 35, false, false, 0x0000FF);
	this->drawLine(5, 50, 195, 50, 0xC0C0C0);
	this->drawString("Idle :", 10, 60, false, false, 0x0);
	this->drawString(this->sys_data.cpuIdle.c_str(), 160 - this->sys_data.cpuIdle.length() * 2, 60, false, false, 0x0);
	SDL_UpdateWindowSurface(this->_win_ptr);
}
