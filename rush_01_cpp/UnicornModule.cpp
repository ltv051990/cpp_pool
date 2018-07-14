/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UnicornModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 11:09:25 by pgritsen          #+#    #+#             */
/*   Updated: 2018/04/15 12:01:09 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UnicornModule.hpp"
#include <iostream>

UnicornModule::UnicornModule(Cor::sys_data_t & sys_data) : AMonitorModule("Magic Unicorn", 440, 440, sys_data) {}

void			UnicornModule::draw(void) const
{
	static int				frame = 0;
	static unsigned			delay = SDL_GetTicks();
	static SDL_Surface		*pony[] = {
		IMG_Load("./resources/images/pony/pony_0.png"),
		IMG_Load("./resources/images/pony/pony_1.png"),
		IMG_Load("./resources/images/pony/pony_2.png"),
		IMG_Load("./resources/images/pony/pony_3.png"),
		IMG_Load("./resources/images/pony/pony_4.png"),
		IMG_Load("./resources/images/pony/pony_5.png"),
		IMG_Load("./resources/images/pony/pony_6.png"),
		IMG_Load("./resources/images/pony/pony_7.png"),
		IMG_Load("./resources/images/pony/pony_8.png"),
		IMG_Load("./resources/images/pony/pony_9.png"),
		IMG_Load("./resources/images/pony/pony_10.png"),
		IMG_Load("./resources/images/pony/pony_11.png")
	};

	for (unsigned i = 0; i < sizeof(pony) / sizeof(*pony); i++)
		if (pony[i] == 0)
		{
			std::cout << "Pony sprites are broken: ./resources/images/pony/pony_" << i << ".png" << std::endl;
			exit(-1);
		}

	if (SDL_GetTicks() - delay > 80)
	{
		delay = SDL_GetTicks();
		frame = (frame + 1) % (sizeof(pony) / sizeof(*pony));
		this->fillBackGround(0xFFFFFF);
		SDL_BlitSurface(pony[frame % (sizeof(pony) / sizeof(*pony))], NULL, this->_win_surf, NULL);
		SDL_UpdateWindowSurface(this->_win_ptr);
	}
}
