// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/07 11:00:23 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/07 11:00:25 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Ncurse.hpp"
#include "Player.class.hpp"
#include "Bullet.class.hpp"
#include "Enemy.class.hpp"
#include <unistd.h>
// #include <cstdlib>
// #include <ctime>
// #include <sys/time.h>
// #include <iostream>
// #include <fstream>
// #include <string>
// #include <sstream>
// #include <clocale>
#define BUL 5
#define EN 10
#define AST 15

int main(void) {
	system("afplay mp3/cs.mp3 &");
	setlocale (LC_ALL,"");
	Ncurse *a = new Ncurse;
	Player *player = new Player;
	a->setPlayer(player);
	int i;
	uint32_t cycle = 0;

	a->draw_player(player->getY(), player->getX());
	while (++cycle)
	{
		if (cycle % 5 == 0)
			a->ast_set();
		a->ast_clen();
		a->ast_moves();
		timeout(0);
		i = getch();
		a->draw_old(player->getY(), player->getX());
		if (i == 32) {
				a->bull_set();
			a->bull_clean();
			a->bull_moves();
			}
		else {
			a->bull_clean();
			a->bull_moves();
		}
		if (cycle % 2 == 1) {
			a->enemy_clen();
			a->enemy_moves();
		}
		if (i == 27)
		{
			endwin();
			system("kill $(pgrep afplay)");
			exit(0);
		}
		else if (i ==  KEY_LEFT) //left
			player->move_left();
		else if (i ==  KEY_RIGHT)//right
			player->move_right();
		else if (i ==  KEY_UP) //left
			player->move_up();
		else if (i ==  KEY_DOWN)//right
			player->move_down();
		a->colision_ship();
		a->draw_player(player->getY(), player->getX());
		if (cycle % 3 == 0)
			a->enemy_set();
		usleep(45000);
		wrefresh(a->getWin());
		a->redraw_bar();
	}
	return 0;
}
