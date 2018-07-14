/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HardMemModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 20:59:22 by pgritsen          #+#    #+#             */
/*   Updated: 2018/04/15 11:56:29 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HardMemModule.hpp"

HardMemModule::HardMemModule(Cor::sys_data_t	& sys_data) : AMonitorModule("Hard Drive", 240, 60, sys_data) {}

void			HardMemModule::draw(void) const
{
	this->fillBackGround(0xFFFFFF);
	this->drawString("Read :", 10, 10, false, false, 0x0);
	this->drawString(this->sys_data.disksRead.c_str(), 150 - this->sys_data.disksRead.length() * 2, 10, true, false, 0xC000);
	this->drawLine(5, 30, 235, 30, 0xC0C0C0);
	this->drawString("Written :", 10, 35, false, false, 0x0);
	this->drawString(this->sys_data.disksWritten.c_str(), 150 - this->sys_data.disksWritten.length() * 2, 35, true, false, 0xFF);
	SDL_UpdateWindowSurface(this->_win_ptr);
}
