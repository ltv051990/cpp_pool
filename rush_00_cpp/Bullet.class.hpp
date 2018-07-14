#ifndef BULLET
#define BULLET

#include <iostream>

class Bullet
{
	private:
		int x;
		int y;

	public:
		Bullet();
		Bullet(int px, int py);
		Bullet(Bullet const & src);
		~Bullet(void);

		// int x;
		// int	y;
		Bullet & operator= (Bullet const & src);
		bool bullet_move();
		int getX() const ;
		int getY() const ;
		void setX(int x);
		void setY(int y);
};

#endif