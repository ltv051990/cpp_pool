// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/05 11:23:37 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/05 11:23:39 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
	FragTrap a1("VASIA");
	FragTrap b1(a1);
	b1.setName("HAVRILO");
	std::cout << "EnergyPoints of " << a1.getName() << " = "  << a1.getEnergyPoints() << std::endl;
	std::cout << "HitPoints of " << a1.getName() << " = " << a1.getHitPoints() << std::endl;

	a1.rangedAttack(b1.getName());
	a1.meleeAttack(b1.getName());
//	b1.takeDamage(a1.getRangedAttackDamage());
//	b1.takeEnergyDamage(a1.getmeleeAttackDamage());
	std::cout << "EnergyPoints of " << a1.getName() << " = "  << a1.getEnergyPoints() << std::endl;
	std::cout << "HitPoints of " << a1.getName() << " = " << a1.getHitPoints() << std::endl;
	a1.beRepaird(1000);
	a1.energyRepaird(1000);
	std::cout << "EnergyPoints of " << a1.getName() << " = "  << a1.getEnergyPoints() << std::endl;
	std::cout << "HitPoints of " << a1.getName() << " = " << a1.getHitPoints() << std::endl;

	b1.vaulthunter_dot_exe("enemy T-72");
	b1.vaulthunter_dot_exe("enemy T-80");
	b1.vaulthunter_dot_exe("enemy T-ARMATA");
	b1.vaulthunter_dot_exe("enemy T-64");

	b1.vaulthunter_dot_exe("enemy T-90");
	std::cout << "EnergyPoints of " << b1.getName() << " = "  << b1.getEnergyPoints() << std::endl;
	std::cout << "HitPoints of " << b1.getName() << " = " << b1.getHitPoints() << std::endl;

	b1.energyRepaird(10);
	std::cout << "EnergyPoints of " << b1.getName() << " = "  << b1.getEnergyPoints() << std::endl;
	std::cout << "HitPoints of " << b1.getName() << " = " << b1.getHitPoints() << std::endl;
	return (0);
}
