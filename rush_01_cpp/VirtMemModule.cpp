/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VirtMemModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 20:59:09 by pgritsen          #+#    #+#             */
/*   Updated: 2018/04/14 23:44:18 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "VirtMemModule.hpp"

VirtMemModule::VirtMemModule(Cor::sys_data_t	& sys_data) : AMonitorModule("Virtual memmory", 200, 60, sys_data) {}

void			VirtMemModule::draw(void) const
{
	this->fillBackGround(0xFFFFFF);
	this->drawString("Vsize :", 10, 10, false, false, 0x0);
	this->drawString(this->sys_data.virtMemSize.c_str(), 160 - this->sys_data.virtMemSize.length() * 2, 10, true, false, 0xFF0000);
	this->drawLine(5, 30, 195, 30, 0xC0C0C0);
	this->drawString("Framework vsize :", 10, 35, false, false, 0x0);
	this->drawString(this->sys_data.virtMemFramSize.c_str(), 160 - this->sys_data.virtMemFramSize.length() * 2, 35, true, false, 0x8C);
	SDL_UpdateWindowSurface(this->_win_ptr);
}
