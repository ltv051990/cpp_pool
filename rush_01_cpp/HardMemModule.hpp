/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HardMemModule.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 20:59:23 by pgritsen          #+#    #+#             */
/*   Updated: 2018/04/14 21:01:35 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARDMEMMODULE_HPP
# define HARDMEMMODULE_HPP

#include "Cor.hpp"
#include "AMonitorModule.hpp"

class HardMemModule : public AMonitorModule
{
	public:
		HardMemModule(Cor::sys_data_t	& sys_data);

		void			draw(void) const;
};

#endif
