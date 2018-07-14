/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserDataModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 20:43:14 by pgritsen          #+#    #+#             */
/*   Updated: 2018/04/14 20:56:51 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USERDATAMODULE_HPP
# define USERDATAMODULE_HPP

#include "Cor.hpp"
#include "AMonitorModule.hpp"

class UserDataModule : public AMonitorModule
{
	public:
		UserDataModule(Cor::sys_data_t	& sys_data);

		void			draw(void) const;
};

#endif
