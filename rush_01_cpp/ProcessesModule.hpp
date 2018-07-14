/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ProcessesModule.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 20:43:43 by pgritsen          #+#    #+#             */
/*   Updated: 2018/04/14 20:45:06 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESSESMODULE_HPP
# define PROCESSESMODULE_HPP

#include "Cor.hpp"
#include "AMonitorModule.hpp"

class ProcessesModule : public AMonitorModule
{
	public:
		ProcessesModule(Cor::sys_data_t	& sys_data);

		void			draw(void) const;
};

#endif
