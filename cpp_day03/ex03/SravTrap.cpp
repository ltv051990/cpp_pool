// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SravTrap.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/05 23:39:59 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/05 23:40:01 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "SravTrap.hpp"
#include <ctime>

//std::string const SravTrap::type = "CLAPTRAPS FR4G-TP";
//int SravTrap::random = 0;

SravTrap::SravTrap() {
	this->hitPoints = 100;
	this->maxHitPoints = 100;
	this->energyPoints = 50;
	this->maxEnergyPoints = 50;
	this->level = 1;
	this->meleeAttackDamage = 20;
	this->rangedAttackDamage = 15;
	this->armorDamageReduction = 3;
	this->energyAttackDamage = 25;
	this->type = "SravTrap";
	std::cout << this->type << " Constructor called!!!" <<std::endl;
}

SravTrap::~SravTrap() {
	std::cout << "Fuck!!! Destructor " << this->type << " called!!!" << std::endl;
}

SravTrap::SravTrap ( std::string const & name ) : ClapTrap (name) {
	this->name = name;
	this->hitPoints = 100;
	this->maxHitPoints = 100;
	this->energyPoints = 50;
	this->maxEnergyPoints = 50;
	this->level = 1;
	this->meleeAttackDamage = 20;
	this->rangedAttackDamage = 15;
	this->armorDamageReduction = 3;
	this->energyAttackDamage = 25;
	this->type = "SravTrap";
	std::cout << this->type << " Constructor called!!!" <<std::endl;
}

SravTrap & SravTrap::operator=( SravTrap const &src ) {
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
//	std::cout << this->type << "Copy Constructor called!!!" <<std::endl;
	return *this;
}

SravTrap::SravTrap( SravTrap const & src ) {
	std::cout << this->type << "Copy Constructor called!!!" <<std::endl;
	*this = src;
}

		///////////////////////////////////////////////////////////////
		///////////////////////    MY ATTACK      /////////////////////
		///////////////////////////////////////////////////////////////

void SravTrap::funnyAttack( std::string const & target ) {
	std::cout << "" << this->type << " use funnyAttack and " << this->name << " attacks " << target << " at range, causing "
	<< this->rangedAttackDamage + 20 << " points of damage!!!" << std::endl;
}

void SravTrap::bustyAttack( std::string const & target ) {
	std::cout << "" << this->type << " use bustyAttack and " << this->name << " attacks " << target << " at range, causing "
	<< this->rangedAttackDamage - 15 << " points of damage!!!" << std::endl;
}

void SravTrap::fuckingAttack( std::string const & target ) {
	std::cout << "" << this->type << " use fuckingAttack and " << this->name << " attacks " << target << " at range, causing "
	<< this->rangedAttackDamage + 10 << " points of damage!!!" << std::endl;
}

void SravTrap::spekingAttack( std::string const & target ) {
	std::cout << "" << this->type << " use spekingAttack and " << this->name << " attacks " << target << " at range, causing "
	<< this->rangedAttackDamage + 50 << " points of damage!!!" << std::endl;
}

void SravTrap::spaceAttack( std::string const & target ) {
	std::cout << "" << this->type << " use spaceAttack and " << this->name << " attacks " << target << " at range, causing "
	<< this->rangedAttackDamage * 3 << " points of damage!!!" << std::endl;
}

		///////////////////////////////////////////////////////////////
		//////////////    Call random attack      /////////////////////
		///////////////////////////////////////////////////////////////

void SravTrap::challengeNewcomer( std::string const & target ) {
	this->random++;
	void (SravTrap::*ukaz[5])( std::string const & target ) = { &SravTrap::funnyAttack, &SravTrap::bustyAttack,
		&SravTrap::fuckingAttack, &SravTrap::spekingAttack, &SravTrap::spaceAttack };
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
