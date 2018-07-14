/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClockModule.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 20:43:27 by pgritsen          #+#    #+#             */
/*   Updated: 2018/04/14 22:39:35 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLOCKMODULE_HPP
# define CLOCKMODULE_HPP

#include "Cor.hpp"
#include "AMonitorModule.hpp"

class ClockModule : public AMonitorModule
{
	public:
		ClockModule(Cor::sys_data_t	& sys_data);

		void			draw(void) const;
};

#endif
