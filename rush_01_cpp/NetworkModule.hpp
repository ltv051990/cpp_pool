/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkModule.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 20:59:29 by pgritsen          #+#    #+#             */
/*   Updated: 2018/04/14 21:00:13 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWORKMODULE_HPP
# define NETWORKMODULE_HPP

#include "Cor.hpp"
#include "AMonitorModule.hpp"

class NetworkModule : public AMonitorModule
{
	public:
		NetworkModule(Cor::sys_data_t	& sys_data);

		void			draw(void) const;
};

#endif
