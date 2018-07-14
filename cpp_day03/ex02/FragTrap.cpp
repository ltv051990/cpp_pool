// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   FragTrap.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/05 11:23:16 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/05 11:23:17 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "FragTrap.hpp"
#include <iostream>
#include <ctime>

//std::string const FragTrap::type = "FragTrap FR4G-TP";
//int FragTrap::random = 0;

FragTrap::FragTrap() {
	this->name = name;
	this->energyPoints = 100;
	this->maxEnergyPoints = 100;
	this->meleeAttackDamage = 30;
	this->rangedAttackDamage = 20;
	this->armorDamageReduction = 5;
	this->energyAttackDamage = 25;
	this->type = "FragTrap";
	std::cout << this->type << " Constructor called!!!" <<std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "Fuck!!! Destructor " << this->type << " called!!!" << std::endl;
}

FragTrap::FragTrap( std::string const & name ) : ClapTrap (name) {
	this->name = name;
	this->energyPoints = 100;
	this->maxEnergyPoints = 100;
	this->meleeAttackDamage = 30;
	this->rangedAttackDamage = 20;
	this->armorDamageReduction = 5;
	this->energyAttackDamage = 25;
	this->type = "FragTrap";
	std::cout << this->type << " Constructor called!!!" <<std::endl;
}

FragTrap & FragTrap::operator=( FragTrap const &src ) {
	this->name = src.getName();
	this->hitPoints = src.getHitPoints();
	this->maxHitPoints = src.getMaxHitPoints();
	this->energyPoints = src.getEnergyPoints();
	this->maxEnergyPoints = src.getMaxEnergyPoints();
	this->level = src.getLevel();
	this->meleeAttackDamage = src.getmeleeAttackDamage();
	this->rangedAttackDamage = src.getRangedAttackDamage();
	this->armorDamageReduction = src.getArmorDamageReduction();
	this->energyAttackDamage = src.getEnergyAttackDamage();
//	std::cout << "Assignation operator called" << std::endl;
	return *this;
}

FragTrap::FragTrap( FragTrap const & src ) {
	std::cout << this->type << "Copy Constructor called!!!" <<std::endl;
	*this = src;
}

		///////////////////////////////////////////////////////////////
		///////////////////////    MY ATTACK      /////////////////////
		///////////////////////////////////////////////////////////////

void FragTrap::intimAttack( std::string const & target ) {
	std::cout << "" << this->type << " use intimAttack and " << this->name << " attacks " << target << " at range, causing "
	<< this->rangedAttackDamage + 5<< " points of damage!!!" << std::endl;
}

void FragTrap::fustAttack( std::string const & target ) {
	std::cout << "" << this->type << " use fustAttack and " << this->name << " attacks " << target << " at range, causing "
	<< this->rangedAttackDamage - 10 << " points of damage!!!" << std::endl;
}

void FragTrap::stupedAttack( std::string const & target ) {
	std::cout << "" << this->type << " use stupedAttack and " << this->name << " attacks " << target << " at range, causing "
	<< this->rangedAttackDamage - 15 << " points of damage!!!" << std::endl;
}

void FragTrap::smartAttack( std::string const & target ) {
	std::cout << "" << this->type << " use smartAttack and " << this->name << " attacks " << target << " at range, causing "
	<< this->rangedAttackDamage + 30 << " points of damage!!!" << std::endl;
}

void FragTrap::hopStopAttack( std::string const & target ) {
	std::cout << "" << this->type << " use hopStopAttack and " << this->name << " attacks " << target << " at range, causing "
	<< this->rangedAttackDamage * 2 << " points of damage!!!" << std::endl;
}

		///////////////////////////////////////////////////////////////
		//////////////    Call random attack      /////////////////////
		///////////////////////////////////////////////////////////////

void FragTrap::vaulthunter_dot_exe( std::string const & target ) {
	this->random++;
	void (FragTrap::*ukaz[5])( std::string const & target ) = { &FragTrap::hopStopAttack, &FragTrap::smartAttack,
		&FragTrap::stupedAttack, &FragTrap::fustAttack, &FragTrap::intimAttack };
	int random = (std::time(nullptr) + random) % 5;
	if (this->energyPoints >= 25) {
		(this->*ukaz[random])(target);
		energyPoints -= 25;
	}
	else {
		std::cout << "YOU DON'T HAVE ENOUGTH ENERGY!!!" << std::endl;
	}
//	std::cout << "energyPoints " << energyPoints << std::endl;
}
