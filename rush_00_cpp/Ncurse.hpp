// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Ncurse.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/07 11:00:51 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/07 11:00:52 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef NCURSE_HPP
#define NCURSE_HPP
#include <iostream>
# include <ncurses.h>
#include "Bullet.class.hpp"
#include "Enemy.class.hpp"
#include "Asteroid.hpp"
#include "Player.class.hpp"
# define WIN_WIDTH 104
# define WIN_HEIGHT 52
# define WIN_HEIGHT2 60
# define WIDTH 100
#define HEIGHT 48
#define BUL 5
#define EN 10
#define AST 15
#define Y_ENEMY 3

class Ncurse
{
	private:
		WINDOW 		*win;
		Player 		*player;
		int live;
		int enemy;
	public:
		Ncurse(void);
		Ncurse ( Ncurse const & src );
		~Ncurse(void);
		Ncurse &operator=( Ncurse const & src);

		void 	pashalka( void );
		void 	hotkey( void );
		void 	draw_player( int x, int y );
		void 	make_border( void );
		void 	make_bare( void );	
		void 	setPlayer(Player *player);

		void  	draw_old(int y, int x);
		void 	draw_new_bul(int y, int x);
		void 	draw_old_bul(int y, int x);
		void 	draw_new_enemy(int y, int x);
		void 	draw_old_enemy(int y, int x);
		void 	ft_er_init( void );
		void 	ft_check_size_win( void );
		void 	colors( void );
		void 	draw_old_ast(int y, int x);
		void	draw_new_ast(int y, int x);
		void 	draw_bar();
		WINDOW	*getWin(void) const ;
		int 	getLive(void) const ;
		int 	getEnemy(void) const ;
		void 	redraw_bar();
		void 	bull_set();
		void 	ast_set();
		void 	bull_moves();
		void 	setLive(int live);
		void 	setEnemy(int enemy);
		void 	ast_clen();
		void 	ast_moves();
		void 	game_over();
		void	enemy_clen();
		void 	enemy_moves();
		void 	enemy_set();
		void 	bull_clean();
		bool 	colision_bul(int i);
		void 	colision_ship();

		Bullet 	*b[BUL];
		Enemy 	*e[EN];
		Asteroid *a[AST];
};

#endif