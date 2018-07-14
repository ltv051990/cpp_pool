/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAMMemModule.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 20:58:56 by pgritsen          #+#    #+#             */
/*   Updated: 2018/04/14 21:03:25 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAMMEMMODULE_HPP
# define RAMMEMMODULE_HPP

#include "Cor.hpp"
#include "AMonitorModule.hpp"

class RAMMemModule : public AMonitorModule
{
	public:
		RAMMemModule(Cor::sys_data_t	& sys_data);

		void			draw(void) const;
};

#endif
