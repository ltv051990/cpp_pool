/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UnicornModule.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 11:09:28 by pgritsen          #+#    #+#             */
/*   Updated: 2018/04/15 11:10:33 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNICORNMODULE_HPP
# define UNICORNMODULE_HPP

#include "Cor.hpp"
#include "AMonitorModule.hpp"

class UnicornModule : public AMonitorModule
{
	public:
		UnicornModule(Cor::sys_data_t	& sys_data);

		void			draw(void) const;
};

#endif
