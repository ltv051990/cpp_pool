#include "Player.class.hpp"
# define WIN_WIDTH 104
# define WIN_HEIGHT 52
# define WIDTH 100
#define  HEIGHT 48

Player::Player(void)
{
	x = WIDTH / 2;
	y = HEIGHT - 3;
}
Player::~Player(){}

Player::Player(Player const & src){
	*this = src;
}

Player & Player::operator=(Player const & src)
{
	this->x = src.x;
	this->y = src.y;
	return *this;
}

void Player::move_left()
{
	if (x > 1)
		x-=2;
}

void Player::move_right()
{
	if (x < WIDTH - 2)
		x+=2;
}

void Player::move_up()
{
	if (y > 1)
		y-=2;
}

void Player::move_down()
{
	if (y < HEIGHT - 2)
		y+=2;
}

int Player::getX( void ) const {
	return this->x;
}

int Player::getY( void ) const {
	return this->y;
}

void Player::setX(int x){
	this->x = x;
}
void Player::setY(int y){
	this->y = y;
}