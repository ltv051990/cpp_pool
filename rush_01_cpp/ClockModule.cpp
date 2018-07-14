/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClockModule.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 20:43:30 by pgritsen          #+#    #+#             */
/*   Updated: 2018/04/15 12:14:45 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClockModule.hpp"

ClockModule::ClockModule(Cor::sys_data_t	& sys_data) : AMonitorModule("Clock", 190, 110, sys_data) {}

void	ClockModule::draw(void) const
{
	this->fillBackGround(0x0);
	this->drawString(this->sys_data.time.c_str(), 30, 10, true, true, 0x00FF00);
	this->drawString(this->sys_data.date.c_str(), 10, 60, true, true, 0x0000FF);
	SDL_UpdateWindowSurface(this->_win_ptr);
}
