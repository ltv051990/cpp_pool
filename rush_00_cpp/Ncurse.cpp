// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Ncurse.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/07 11:00:43 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/07 11:00:46 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Ncurse.hpp"
#include <string>
#include <iostream>
#include <cstdlib>
#include <clocale>

Ncurse::Ncurse(){
	if (!(initscr()))
		ft_er_init();
	this->win = newwin(HEIGHT, WIDTH, 2, 2);
	noecho();
	ft_check_size_win();
	curs_set(0);
	keypad(stdscr, TRUE);
	nodelay(this->win, FALSE);  
	start_color();
	colors();
	make_border();
	draw_bar();
	refresh();
	this->live = 3;
	wrefresh(this->win);
	for (int a = 0; a < BUL; a++)
		b[a] = NULL;
	for (int c = 0; c < EN; c++)
		e[c] = NULL;
	for (int q = 0; q < AST; q++)
		a[q] = NULL;
}

Ncurse::Ncurse ( Ncurse const & src ) {
}

void Ncurse::setPlayer(Player *player) {
	this->player = player;
}

Ncurse & Ncurse::operator=( Ncurse const & src) {
	this->win = src.getWin();
	return	*this;
}

void Ncurse::ft_check_size_win() {
	if (COLS < WIN_WIDTH)
	{
		endwin();
		std::cout << "Too small window width!!! Min width must be 100 COLUMS" << std::endl;
		exit(0);
	}
	if (LINES < WIN_HEIGHT2)
	{
		endwin();
		std::cout << "Too small window height!!! Min height must be 100 LINES" << std::endl;
		exit(0);
	}
}

void	Ncurse::ft_er_init(void)
{
	std::cout << "ncurses problem with memory" << std::endl;
	exit(0);
}

Ncurse::~Ncurse() {
	endwin();
}

void Ncurse::make_border() {
	int y;
	int x;

	y = 0;
	x = 0;
	refresh();
	attron(COLOR_PAIR(18));
	while (y < WIN_HEIGHT2 - 1)
	{
		mvaddch(y, 0, '@');
		mvaddch(y, WIN_WIDTH - 1, '@');
		y++;
	}
	while (x < WIN_WIDTH)
	{
		mvaddch(0, x, '@');
		mvaddch(WIN_HEIGHT - 1, x, '@');
		mvaddch(WIN_HEIGHT2 - 1, x, '@');
		x++;
	}
	wrefresh(this->win);
}

void Ncurse::draw_bar(void) {
	attron(COLOR_PAIR(15) | A_BOLD);
	setlocale (LC_ALL,"");
	mvprintw(WIN_HEIGHT + 2, 30, "LIVES        ");
	mvprintw(WIN_HEIGHT + 4, 30, "KILLED ENEMY ");
	refresh();
}

WINDOW	*Ncurse::getWin() const { return win; }
int Ncurse::getLive(void) const { return live; }
int Ncurse::getEnemy(void) const { return enemy; }

void Ncurse::setLive(int live) { this->live = live;}
void Ncurse::setEnemy(int enemy) { this->enemy = enemy; }

void Ncurse::colors() {
	init_color(COLOR_CYAN, 300, 300, 300);
	init_pair(1,  COLOR_GREEN,   COLOR_BLACK); // color first player
	init_pair(2,  COLOR_RED,     COLOR_BLACK); // color second player
	init_pair(3,  COLOR_YELLOW,  COLOR_BLACK); // color third player
	init_pair(4,  COLOR_BLUE,    COLOR_BLACK); // color four player
	init_pair(15, COLOR_WHITE, COLOR_BLACK); // white color for bar
	init_pair(17, COLOR_BLACK, COLOR_BLACK); // black color for space in map
	init_pair(18, COLOR_CYAN, COLOR_CYAN); // color border
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
//			PLAYER
///////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

void Ncurse::draw_old(int y, int x) {
	wattron(this->win, COLOR_PAIR(17));
	mvwprintw(this->win, y, x, "%c", 'M');
}

void Ncurse::draw_player(int y, int x) {
	wattron(this->win, COLOR_PAIR(1));
	mvwprintw(this->win, y, x, "%c", 'M');
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
//			ENEMY
///////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

void Ncurse::draw_old_enemy(int y, int x) {
	wattron(this->win, COLOR_PAIR(17));
	mvwprintw(this->win, y, x, "%c", 'W');
}

void Ncurse::draw_new_enemy(int y, int x) {
	wattron(this->win, COLOR_PAIR(2));
	mvwprintw(this->win, y, x, "%C", 'W');
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
//			OLD
///////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

void Ncurse::draw_old_bul(int y, int x) {
	wattron(this->win, COLOR_PAIR(17));
	mvwprintw(this->win, y, x, "%c", '|');
}

void Ncurse::draw_new_bul(int y, int x) {
	wattron(this->win, COLOR_PAIR(1));
	mvwprintw(this->win, y, x, "%c", '|');
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
//			ASTEROID
///////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

void Ncurse::draw_old_ast(int y, int x) {
	wattron(this->win, COLOR_PAIR(17));
	mvwprintw(this->win, y, x, "%c", '0');
}

void Ncurse::draw_new_ast(int y, int x) {
	wattron(this->win, COLOR_PAIR(4));
	mvwprintw(this->win, y, x, "%c", 'O');
}

void Ncurse::redraw_bar() {
	attron(COLOR_PAIR(15));
	if (live == 0)
		mvprintw(WIN_HEIGHT + 2, 45, "WE NEED THE BEST GRADE!!!");
	else if (live == 1)
		mvprintw(WIN_HEIGHT + 2, 45, "%c    ", 'M');
	else if (live == 3 || live  == 2)
		mvprintw(WIN_HEIGHT + 2, 45, "%c %c ", 'M', 'M');
	attron(COLOR_PAIR(15) | A_BOLD);
	mvprintw(WIN_HEIGHT + 4, 45, "%d     ", enemy);
	refresh();
}

void  Ncurse::ast_set() {
	for (int i = 0; i < AST; i++) {
		if 	(a[i] == NULL) {
				a[i] = new Asteroid();
				break ;
		}
	}
}

void Ncurse::ast_clen() {
	for (int i = 0; i < AST; i++) {
		if 	(a[i] != NULL) 
				draw_old_ast(a[i]->getY(), a[i]->getX());
	}
}

void  Ncurse::ast_moves() {
	for (int i = 0; i < AST; i++) {
		if 	(a[i] != NULL) {
			if (a[i]->asteroid_move())
				draw_new_ast(a[i]->getY(), a[i]->getX());
			else
			{
				draw_old_ast(a[i]->getY(), a[i]->getX());
				delete a[i];
				a[i] = NULL;
			}
		}
	}
}

void Ncurse::game_over() {
	redraw_bar();
	wattron(win, COLOR_PAIR(2));
	mvwprintw(win, 13, 0, "%s", "   ,***************        ................      ...........  ............   ,********************");
	mvwprintw(win, 14, 0, "%s", "   &@@@@@@@@@@@@@@@.       @@@@@@@@@@@@@@@@.     @@@@@@@@@@@* (@@@@@@@@@@@   &@@@@@@@@@@@@@@@@@@@@");
	mvwprintw(win, 15, 0, "%s", " @@@@@@@                 @@@@@@@      (@@@@@@@   @@@@@@@  @@@@@@@  @@@@@@@   &@@@@@@");
	mvwprintw(win, 16, 0, "%s", " @@@@@@@                 @@@@@@@      (@@@@@@@   @@@@@@@  @@@@@@@  @@@@@@@   &@@@@@@");
	mvwprintw(win, 17, 0, "%s", " @@@@@@@                 @@@@@@@      (@@@@@@@   @@@@@@@  @@@@@@@  @@@@@@@   &@@@@@@");
	mvwprintw(win, 18, 0, "%s", " @@@@@@@  @@@@@@@@@@@@   @@@@@@@      (@@@@@@@   @@@@@@@  @@@@@@@  @@@@@@@   &@@@@@@@@@@@@@@@@@@@@");
	mvwprintw(win, 19, 0, "%s", " @@@@@@@       @@@@@@@   @@@@@@@      (@@@@@@@   @@@@@@@  @@@@@@@  @@@@@@@   &@@@@@@,");
	mvwprintw(win, 20, 0, "%s", " @@@@@@@       @@@@@@&   @@@@@@@%%%%%%&@@@@@@@   @@@@@@@  @@@@@@@  @@@@@@@   &@@@@@@,");
	mvwprintw(win, 21, 0, "%s", " @@@@@@@       @@@@@@@   @@@@@@@@@@@@@@@@@@@@@   @@@@@@@  @@@@@@@  @@@@@@@   &@@@@@@,");
	mvwprintw(win, 22, 0, "%s", "   &@@@@@@@@@@@@@@@*     @@@@@@@      .@@@@@@@   @@@@@@@  @@@@@@@  &@@@@@@   &@@@@@@@@@@@@@@@@@@@@");
	mvwprintw(win, 25, 0, "%s", "    @@@@@@@@@@@@@@@@     #@@@@@@       @@@@@@@   &@@@@@@@@@@@@@@@@@@@@   @@@@@@@@@@@@@@@@@@(");
	mvwprintw(win, 26, 0, "%s", "   @@@@@@@@@@@@@@@@@@    %@@@@@@       @@@@@@@   &@@@@@@@@@@@@@@@@@@@@   @@@@@@@@@@@@@@@@@@&");
	mvwprintw(win, 27, 0, "%s", " /@@@@@@&      @@@@@@@   %@@@@@@       @@@@@@@   &@@@@@@/                @@@@@@@       @@@@@@&");
	mvwprintw(win, 28, 0, "%s", " /@@@@@@&      @@@@@@@   %@@@@@@       @@@@@@@   &@@@@@@/                @@@@@@@       @@@@@@&");
	mvwprintw(win, 29, 0, "%s", " /@@@@@@&      @@@@@@@   %@@@@@@       @@@@@@@   &@@@@@@@&&@@&&@@&&&&&   @@@@@@@@&&&&&&@@@@@/,");
	mvwprintw(win, 30, 0, "%s", " /@@@@@@&      @@@@@@@   %@@@@@@       @@@@@@@   &@@@@@@@@@@@@@@@@@@@@   @@@@@@@@@@@@@@@@@@@");
	mvwprintw(win, 31, 0, "%s", " /@@@@@@&      @@@@@@@   %@@@@@@       @@@@@@@   &@@@@@@*                @@@@@@@       @@@@@@@");
	mvwprintw(win, 32, 0, "%s", " /@@@@@@&      @@@@@@@     *@@@@@@&  @@@@@@@     &@@@@@@*                @@@@@@@       @@@@@@@");
	mvwprintw(win, 33, 0, "%s", " /@@@@@@&      @@@@@@@     *@@@@@@&  @@@@@@@     &@@@@@@*                @@@@@@@       @@@@@@@");
	mvwprintw(win, 34, 0, "%s", " *@@@@@@&......@@@@@@@     ,@@@@@@& .@@@@@@@     &@@@@@@*                @@@@@@@       @@@@@@@");
	mvwprintw(win, 35, 0, "%s", "    @@@@@@@@@@@@@@@@            @@@@@@@.         &@@@@@@@@@@@@@@@@@@@@   @@@@@@@       @@@@@@@");
	wrefresh(win);
	int i = 0;
	while (i != 27)
		i = getch();
	endwin();
	system("kill $(pgrep afplay) > /dev/null 2>&1");
	exit(0);
}

void	Ncurse::enemy_clen() {
	for (int i = 0; i < EN; i++) {
		if 	(e[i] != NULL) 
				draw_old_enemy(e[i]->getY(), e[i]->getX());
	}
}

void Ncurse::enemy_moves() {
	for (int i = 0; i < EN; i++) {
		if 	(e[i] != NULL) {
			if (e[i]->enemy_move())
				draw_new_enemy(e[i]->getY(), e[i]->getX());
			else
			{
				draw_old_enemy(e[i]->getY(), e[i]->getX());
				delete e[i];
				e[i] = NULL;
			}
		}
	}
}

void Ncurse::enemy_set() {
	for (int i = 0; i < EN; i++) {
		if 	(e[i] == NULL) {
				e[i] = new Enemy();
				break ;
		}
	}
}

void Ncurse::bull_clean() {
	for (int i = 0; i < BUL; i++) {
		if 	(b[i] != NULL) 
				draw_old_bul(b[i]->getY(), b[i]->getX());
	}
}

bool Ncurse::colision_bul(int i) {
	for (int index = 0; index < EN; index++){
		if (e[index] != NULL) {
			if ((b[i]->getX() == e[index]->getX()) && (b[i]->getY() == e[index]->getY())) {
				draw_old_enemy(e[index]->getY(), e[index]->getX());
				delete e[index];
				e[index] = NULL;
				draw_old_bul(b[i]->getY(), b[i]->getX());
				delete b[i];
				b[i] = NULL;
				setEnemy(enemy + 1);
				return true;
			}
		}
	}
	return (false);
}

void Ncurse::bull_set() {
	for (int i = 0; i < BUL; i++) {
		if 	(b[i] == NULL) {
				b[i] = new Bullet(player->getX(), player->getY());
				system("afplay mp3/lazer.wav & > /dev/null 2>&1");
				break ;
		}
	}
}

void Ncurse::bull_moves(){
	for (int i = 0; i < BUL; i++) {
		if 	(b[i] != NULL) {
			if (b[i]->bullet_move()){
				if (colision_bul(i))
					break ;
					draw_new_bul(b[i]->getY(), b[i]->getX());
			}
			else
			{
				draw_old_bul(b[i]->getY(), b[i]->getX());
				delete b[i];
				b[i] = NULL;
			}
		}
	}
}

void Ncurse::colision_ship() {
	for (int i = 0; i < EN; i++) {
		if (e[i] != NULL)
			if ((e[i]->getX() == player->getX()) && (e[i]->getY() == player->getY())) {
				if (live == 0)
					game_over();
				else
					live--;
			}
	}
}
