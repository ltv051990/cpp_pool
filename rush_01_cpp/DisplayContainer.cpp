/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DisplayContainer.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:27:31 by pgritsen          #+#    #+#             */
/*   Updated: 2018/04/15 16:28:47 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DisplayContainer.hpp"

DisplayContainer::DisplayContainer(Cor::sys_data_t & sys_data) : sys_data(sys_data)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		exit (-1);
	if (TTF_Init() < 0)
		exit (-1);
	if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) < 0)
		exit (-1);

	if (sys_data.all_mode || sys_data.flags.find("cpu") != std::string::npos)
		this->_modules.push_back(new CpuLoadModule(sys_data));
	if (sys_data.all_mode || sys_data.flags.find("pi") != std::string::npos)
		this->_modules.push_back(new ProcessesModule(sys_data));
	if (sys_data.all_mode || sys_data.flags.find("dt") != std::string::npos)
		this->_modules.push_back(new ClockModule(sys_data));
	if (sys_data.all_mode || sys_data.flags.find("hm") != std::string::npos)
		this->_modules.push_back(new HardMemModule(sys_data));
	if (sys_data.all_mode || sys_data.flags.find("rm") != std::string::npos)
		this->_modules.push_back(new RAMMemModule(sys_data));
	if (sys_data.all_mode || sys_data.flags.find("net") != std::string::npos)
		this->_modules.push_back(new NetworkModule(sys_data));
	if (sys_data.all_mode || sys_data.flags.find("hu") != std::string::npos)
		this->_modules.push_back(new UserDataModule(sys_data));
	if (sys_data.all_mode || sys_data.flags.find("os") != std::string::npos)
		this->_modules.push_back(new OSInfoModule(sys_data));
	if (sys_data.all_mode || sys_data.flags.find("vm") != std::string::npos)
		this->_modules.push_back(new VirtMemModule(sys_data));
	if (sys_data.all_mode || sys_data.flags.find("uni") != std::string::npos)
		this->_modules.push_back(new UnicornModule(sys_data));
}

DisplayContainer::DisplayContainer(DisplayContainer const & sys_data) : _modules(sys_data._modules), sys_data(sys_data.sys_data) {}

DisplayContainer::~DisplayContainer(void) {
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}

DisplayContainer	&DisplayContainer::operator = (DisplayContainer const & elem)
{
	this->_modules = elem._modules;
	return (*this);
}

void	DisplayContainer::loop(void)
{
	SDL_Event		e;

	if (this->_modules.empty())
		exit(0);
	for (unsigned i = 0; i < this->_modules.size(); i++)
		this->_modules[i]->draw();
	while (SDL_PollEvent(&e))
		if (e.type == SDL_QUIT)
			exit(0);
		else if (e.window.event == SDL_WINDOWEVENT_CLOSE
			|| (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE))
			this->_deleteWindow(e.window.windowID);
}

void	DisplayContainer::_deleteWindow(int window_id)
{
	for (unsigned i = 0; i < this->_modules.size(); i++)
		if (this->_modules[i]->id == window_id)
		{
			delete this->_modules[i];
			this->_modules.erase(this->_modules.begin() + i, this->_modules.begin() + i + 1);
			break ;
		}
}
