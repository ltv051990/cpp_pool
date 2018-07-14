// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   NinjaTrap.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/06 15:19:26 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/06 15:19:28 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(): ClapTrap() {
	this->name = "XZ";
	this->hitPoints = 60;
	this->maxHitPoints = 60;
	this->energyPoints = 120;
	this->maxEnergyPoints = 120;
	this->meleeAttackDamage = 60;
	this->rangedAttackDamage = 5;
	this->armorDamageReduction = 0;
	this->energyAttackDamage = 25;
	this->type = "NinjaTrap";
	std::cout << this->type << " default constructor created!!!" << std::endl;
}

NinjaTrap::NinjaTrap(std::string const & name): ClapTrap(name)
{
	this->name = name;
	this->hitPoints = 60;
	this->maxHitPoints = 60;
	this->energyPoints = 120;
	this->maxEnergyPoints = 120;
	this->meleeAttackDamage = 60;
	this->energyAttackDamage = 25;
	this->rangedAttackDamage = 5;
	this->armorDamageReduction = 0;
	std::cout << this->type << " default with name constructor created!!!" << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap const &src)
{
	std::cout << this->type << "Copy constuctor called" << std::endl;
	*this = src;
}

NinjaTrap::~NinjaTrap()
{
	std::cout << this->type << "Destructor called" << std::endl;
}

NinjaTrap & NinjaTrap::operator=( NinjaTrap const &src ) {
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

void	NinjaTrap::ninjaShoebox(NinjaTrap const &target) const {
	std::cout << "ROBO " << this->type << this->name << " KILL WITH KATANA " << target.getName() << " WITH STUPED NAME !!!" << std::endl;
};

void	NinjaTrap::ninjaShoebox(ClapTrap const &target) const {
	std::cout << "ROBO " << this->type << this->name << " KILL WITH KATANA " << target.getName() << " WITH STUPED NAME !!!" << std::endl;
};

void	NinjaTrap::ninjaShoebox(FragTrap const &target) const {
	std::cout << "ROBO " << this->type << this->name << " KILL WITH KATANA " << target.getName() << " WITH STUPED NAME !!!" << std::endl;
};

void	NinjaTrap::ninjaShoebox(SravTrap const &target) const {
	std::cout << "ROBO " << this->type << this->name << " KILL WITH KATANA " << target.getName() << " WITH STUPED NAME !!!" << std::endl;
};
