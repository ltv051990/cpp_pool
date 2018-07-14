#ifndef PLAYER
#define PLAYER

#include <iostream>

class Player
{
	private:
	int x;
	int y;

public:
	Player(void);
	~Player(void);

	Player(Player const & src);
	Player & operator=(Player const & src);

	void move_left();
	void move_right();
	void move_up();
	void move_down();
	int getX() const ;
	int getY() const ;
	void setX(int x);
	void setY(int y);
};

#endif