/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CpuLoadModule.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 19:54:32 by pgritsen          #+#    #+#             */
/*   Updated: 2018/04/14 20:03:45 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPULOADMODULE_HPP
# define CPULOADMODULE_HPP

#include "Cor.hpp"
#include "AMonitorModule.hpp"

class CpuLoadModule : public AMonitorModule
{
	public:
		CpuLoadModule(Cor::sys_data_t	& sys_data);

		void			draw(void) const;
};

#endif
