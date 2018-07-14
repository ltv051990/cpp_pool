#ifndef ENEMY
#define ENEMY
#include <iostream>
#define HEIGHT 48
# define WIDTH 100

class Enemy
{
	private:
		int x;
		int	y;
	public:
		Enemy(void);
		Enemy(Enemy const & src);
		~Enemy(void);

		Enemy & operator= (Enemy const & src);
		bool enemy_move();
		int getX() const ;
		int getY() const ;
		void setX(int x);
		void setY(int y);

};

#endif