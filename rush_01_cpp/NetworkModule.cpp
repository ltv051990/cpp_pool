/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 20:59:31 by pgritsen          #+#    #+#             */
/*   Updated: 2018/04/14 23:19:19 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NetworkModule.hpp"

NetworkModule::NetworkModule(Cor::sys_data_t	& sys_data) : AMonitorModule("Network", 200, 80, sys_data) {}

void			NetworkModule::draw(void) const
{
	this->fillBackGround(0xFFFFFF);
	this->drawString("Packets", 80, 10, true, false, 0x0);
	this->drawString("In :", 10, 35, false, false, 0x0);
	this->drawString(this->sys_data.packets_in.c_str(), 120 - this->sys_data.packets_in.length() * 2, 35, true, false, 0x8C8C00);
	this->drawLine(5, 50, 195, 50, 0xC0C0C0);
	this->drawString("Out :", 10, 60, false, false, 0x0);
	this->drawString(this->sys_data.packets_out.c_str(), 120 - this->sys_data.packets_out.length() * 2, 60, true, false, 0x8C8C);
	SDL_UpdateWindowSurface(this->_win_ptr);
}
