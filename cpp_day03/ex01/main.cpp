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
#include "SravTrap.hpp"

#include <iostream>

int main(void)
{

	std::cout << std::endl << ">>>>>>>>>>>>> WELCOME TO THE ROBO WARS <<<<<<<<<<<<<<" << std::endl << std::endl;


	std::cout << std::endl << ">>>>>>>>>>>>> WELCOME TO THE FragTrap PART <<<<<<<<<<<<<<" << std::endl << std::endl;

	{
		FragTrap a1("FragTrap VASIA");
		FragTrap b1(a1);
		b1.setName("FragTrap HAVRILO");
		std::cout << "EnergyPoints of " << a1.getName() << " = "  << a1.getEnergyPoints() << std::endl;
		std::cout << "HitPoints of " << a1.getName() << " = " << a1.getHitPoints() << std::endl;

		a1.rangedAttack("rashka");
		a1.meleeAttack("parashka");
		a1.takeDamage(100);
		a1.takeEnergyDamage(100);
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

		b1.energyRepaird(100);
		std::cout << "EnergyPoints of " << b1.getName() << " = "  << b1.getEnergyPoints() << std::endl;
		std::cout << "HitPoints of " << b1.getName() << " = " << b1.getHitPoints() << std::endl;
	}

	std::cout << std::endl << ">>>>>>>>>>>>> WELCOME TO THE SravTrap PART <<<<<<<<<<<<<<" << std::endl << std::endl;

	{
		SravTrap a1("SravTrap VASIA");
		SravTrap b1(a1);
		b1.setName("SravTrap HAVRILO");
		std::cout << "EnergyPoints of " << a1.getName() << " = "  << a1.getEnergyPoints() << std::endl;
		std::cout << "HitPoints of " << a1.getName() << " = " << a1.getHitPoints() << std::endl;

		a1.rangedAttack("rashka");
		a1.meleeAttack("parashka");
		a1.takeDamage(100);
		a1.takeEnergyDamage(100);
		std::cout << "EnergyPoints of " << a1.getName() << " = "  << a1.getEnergyPoints() << std::endl;
		std::cout << "HitPoints of " << a1.getName() << " = " << a1.getHitPoints() << std::endl;
		a1.beRepaird(1000);
		a1.energyRepaird(1000);
		std::cout << "EnergyPoints of " << a1.getName() << " = "  << a1.getEnergyPoints() << std::endl;
		std::cout << "HitPoints of " << a1.getName() << " = " << a1.getHitPoints() << std::endl;

		b1.challengeNewcomer("enemy BTR-80");
		b1.challengeNewcomer("enemy BMP");

		b1.challengeNewcomer("enemy BDRDM");
		std::cout << "EnergyPoints of " << b1.getName() << " = "  << b1.getEnergyPoints() << std::endl;
		std::cout << "HitPoints of " << b1.getName() << " = " << b1.getHitPoints() << std::endl;

		b1.energyRepaird(100);
		std::cout << "EnergyPoints of " << b1.getName() << " = "  << b1.getEnergyPoints() << std::endl;
		std::cout << "HitPoints of " << b1.getName() << " = " << b1.getHitPoints() << std::endl;
	}

	std::cout << std::endl << ">>>>>>>>>>>>> TO BE CONTINUED <<<<<<<<<<<<<<" << std::endl << std::endl;

	return (0);
}
