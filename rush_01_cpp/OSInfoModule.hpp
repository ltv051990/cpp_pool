/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSInfoModule.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 20:42:53 by pgritsen          #+#    #+#             */
/*   Updated: 2018/04/14 20:58:09 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSINFOMODULE_HPP
# define OSINFOMODULE_HPP

#include "Cor.hpp"
#include "AMonitorModule.hpp"

class OSInfoModule : public AMonitorModule
{
	public:
		OSInfoModule(Cor::sys_data_t	& sys_data);

		void			draw(void) const;
};

#endif
