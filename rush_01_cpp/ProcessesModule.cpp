/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ProcessesModule.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 20:43:41 by pgritsen          #+#    #+#             */
/*   Updated: 2018/04/14 23:04:03 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ProcessesModule.hpp"

ProcessesModule::ProcessesModule(Cor::sys_data_t	& sys_data) : AMonitorModule("Processes", 200, 110, sys_data) {}

void			ProcessesModule::draw(void) const
{
	this->fillBackGround(0xFFFFFF);
	this->drawString("Total :", 10, 10, false, false, 0x0);
	this->drawString(this->sys_data.proc_total.c_str(), 160 - this->sys_data.proc_total.length() * 2, 10, true, false, 0x0);
	this->drawLine(5, 25, 195, 25, 0xC0C0C0);
	this->drawString("Run :", 10, 35, false, false, 0x0);
	this->drawString(this->sys_data.proc_run.c_str(), 160 - this->sys_data.proc_run.length() * 2, 35, true, false, 0x008C00);
	this->drawLine(5, 50, 195, 50, 0xC0C0C0);
	this->drawString("Sleep :", 10, 60, false, false, 0x0);
	this->drawString(this->sys_data.proc_sleep.c_str(), 160 - this->sys_data.proc_sleep.length() * 2, 60, true, false, 0x0000FF);
	this->drawLine(5, 75, 195, 75, 0xC0C0C0);
	this->drawString("Threads :", 10, 85, false, false, 0x0);
	this->drawString(this->sys_data.threads.c_str(), 160 - this->sys_data.threads.length() * 2, 85, true, false, 0x008C8C);
	SDL_UpdateWindowSurface(this->_win_ptr);
}