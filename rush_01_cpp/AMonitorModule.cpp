/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMonitorModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 15:06:59 by pgritsen          #+#    #+#             */
/*   Updated: 2018/04/14 23:03:30 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMonitorModule.hpp"
#include <iostream>
#include <cmath>

int	AMonitorModule::_last_w_x = 10;
int	AMonitorModule::_last_w_y = 0;

AMonitorModule::AMonitorModule(std::string const & title, int w, int h, Cor::sys_data_t	& sys_data)
	: _title(title), sys_data(sys_data), _w(w), _h(h)
{
	SDL_DisplayMode dm;
	if (SDL_GetDesktopDisplayMode(0, &dm) != 0)
		exit (-1);

	if (_last_w_y == 0)
		_last_w_y = dm.h / 2 - 100;

	this->_win_ptr = SDL_CreateWindow(this->_title.c_str(), _last_w_x,
								_last_w_y, this->_w, this->_h, SDL_WINDOW_ALLOW_HIGHDPI);
	_last_w_x += w;
	if (_last_w_x > dm.w - 10)
	{
		_last_w_x = 10;
		_last_w_y += h;
	}
	this->_win_surf = SDL_GetWindowSurface(this->_win_ptr);
	this->id = SDL_GetWindowID(this->_win_ptr);
}

AMonitorModule::AMonitorModule(AMonitorModule const & copy) : _win_ptr(copy._win_ptr), _win_surf(copy._win_surf), sys_data(copy.sys_data) {}

AMonitorModule	&AMonitorModule::operator = (AMonitorModule const & elem)
{
	this->_win_ptr = elem._win_ptr;
	this->_win_surf = elem._win_surf;
	return (*this);
}

AMonitorModule::~AMonitorModule(void)
{
	SDL_DestroyWindow(this->_win_ptr);
}

void	AMonitorModule::drawString(char const * text, int x, int y, bool b, bool big, unsigned c) const
{
	static TTF_Font	*regular = TTF_OpenFont("./resources/fonts/Regular.ttf", 12);
	static TTF_Font	*big_f = TTF_OpenFont("./resources/fonts/Bold.ttf", 32);
	static TTF_Font	*bold = TTF_OpenFont("./resources/fonts/Bold.ttf", 12);

	SDL_Color	color;
	SDL_Surface	*text_surf;
	SDL_Rect	pos = {x, y, 0, 0};

	if (!regular || !bold) {
		std::cout << "Font's are broken!" << std::endl;
		exit(0) ;
	}

	color = (SDL_Color){.r = c >> 16 & 0xFF,
						.g = c >> 8 & 0xFF,
						.b = c & 0xFF,
						.a = c >> 24 & 0xFF};
	if (big)
		text_surf = TTF_RenderText_Blended(big_f, text, color);
	else if (b)
		text_surf = TTF_RenderText_Blended(bold, text, color);
	else
		text_surf = TTF_RenderText_Blended(regular, text, color);
	if (!text_surf) {
		std::cout << "Some error's occured!" << std::endl;
		exit(0) ;
	}
	SDL_BlitSurface(text_surf, NULL, this->_win_surf, &pos);
	SDL_FreeSurface(text_surf);
}

void	AMonitorModule::fillBackGround(unsigned color) const
{
	unsigned	*pixels = static_cast<unsigned *>(this->_win_surf->pixels);
	for (int i = 0; i < this->_win_surf->w * this->_win_surf->h; i++)
		pixels[i] = color;
}

void	AMonitorModule::drawLine(int x1, int y1, int x2, int y2, unsigned color) const
{
	unsigned	*pixels = static_cast<unsigned *>(this->_win_surf->pixels);
	double		t;
	double		k;
	int			dx;
	int			dy;

	k = 1.0 / sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	t = -k;
	while ((t += k) <= 1.0)
	{
		dx = roundf(x1 + (x2 - x1) * t);
		dy = roundf(y1 + (y2 - y1) * t);
		if (dy >= 0 && dy < this->_win_surf->h && dx >= 0 && dx < this->_win_surf->w)
				pixels[dy * this->_win_surf->w + dx] = color;
	}
}

void	AMonitorModule::drawLine(int x1, int y1, int x2, int y2, unsigned color, int h) const
{
	for (int i = 0; i < h; i++)
		if (x1 == x2)
			this->drawLine(x1 + i, y1, x2 + i, y2, color);
		else
			this->drawLine(x1, y1 + i, x2, y2 + i, color);
}
