/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 15:07:02 by pgritsen          #+#    #+#             */
/*   Updated: 2018/04/14 23:02:52 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMONITORMODULE_HPP
# define AMONITORMODULE_HPP

#include "IMonitorModule.hpp"
#include "Cor.hpp"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <string>

class AMonitorModule : public IMonitorModule
{
	public:
		AMonitorModule(std::string const & title, int w, int h, Cor::sys_data_t	& sys_data);
		virtual ~AMonitorModule(void);

		void	stopModule(AMonitorModule *module);
		void	drawString(char const * text, int x, int y, bool b, bool big, unsigned c) const;
		void	fillBackGround(unsigned color) const;
		void	drawLine(int x1, int y1, int x2, int y2, unsigned color) const;
		void	drawLine(int x1, int y1, int x2, int y2, unsigned color, int h) const;

		int		id;

	private:
		AMonitorModule(void);
		AMonitorModule(AMonitorModule const & copy);
		AMonitorModule	&operator = (AMonitorModule const & elem);

		static int	_last_w_x;
		static int	_last_w_y;

	protected:
		SDL_Window		*_win_ptr;
		SDL_Surface		*_win_surf;
		std::string		_title;
		Cor::sys_data_t	& sys_data;
		int				_w;
		int				_h;
};

#endif
