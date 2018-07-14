/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VirtMemModule.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 20:59:12 by pgritsen          #+#    #+#             */
/*   Updated: 2018/04/14 23:41:53 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIRTMEMMODULE_HPP
# define VIRTMEMMODULE_HPP

#include "Cor.hpp"
#include "AMonitorModule.hpp"

class VirtMemModule : public AMonitorModule
{
	public:
		VirtMemModule(Cor::sys_data_t	& sys_data);

		void			draw(void) const;
};

#endif
