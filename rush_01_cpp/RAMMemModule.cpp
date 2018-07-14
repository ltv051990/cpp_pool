/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAMMemModule.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 20:58:53 by pgritsen          #+#    #+#             */
/*   Updated: 2018/04/14 23:13:57 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RAMMemModule.hpp"

RAMMemModule::RAMMemModule(Cor::sys_data_t	& sys_data) : AMonitorModule("RAM memmory", 200, 60, sys_data) {}

void			RAMMemModule::draw(void) const
{
	this->fillBackGround(0xFFFFFF);
	this->drawString("Used :", 10, 10, false, false, 0x0);
	this->drawString(this->sys_data.physMemUs.c_str(), 160 - this->sys_data.physMemUs.length() * 2, 10, true, false, 0xFF0000);
	this->drawLine(5, 30, 195, 30, 0xC0C0C0);
	this->drawString("Free :", 10, 35, false, false, 0x0);
	this->drawString(this->sys_data.physMemUnus.c_str(), 160 - this->sys_data.physMemUnus.length() * 2, 35, true, false, 0x8C);
	SDL_UpdateWindowSurface(this->_win_ptr);
}
