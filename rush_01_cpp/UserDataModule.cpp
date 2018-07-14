/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserDataModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 20:43:11 by pgritsen          #+#    #+#             */
/*   Updated: 2018/04/14 23:29:55 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UserDataModule.hpp"

UserDataModule::UserDataModule(Cor::sys_data_t	& sys_data) : AMonitorModule("User Data", 300, 115, sys_data) {}

void			UserDataModule::draw(void) const
{
	this->fillBackGround(0xFFFFFF);
	this->drawString(this->sys_data.username.c_str(), 150 - this->sys_data.username.length() * 8.3, 10, false, true, 0xFF0000);
	this->drawLine(5, 54, 295, 54, 0x004200, 2);
	this->drawString(this->sys_data.hostname.c_str(), 150 - this->sys_data.hostname.length() * 8.3, 60, false, true, 0xFF);
	SDL_UpdateWindowSurface(this->_win_ptr);
}
