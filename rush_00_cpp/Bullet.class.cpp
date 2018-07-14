#include "Bullet.class.hpp"

Bullet::Bullet(){
};

Bullet::Bullet(int px, int py) {
	x = px;
	y = py;
};

Bullet::Bullet(Bullet const & src){
	*this = src;
}

Bullet::~Bullet(void){};

Bullet & Bullet::operator=(Bullet const & src)
{
	this->x = src.x;
	this->y = src.y;

	return *this;
}

bool Bullet::bullet_move()
{
	if (y > 0) {
		y--;
		return true;
	}
	return false;
}
int Bullet::getX( void ) const {
	return this->x;
}

int Bullet::getY( void ) const {
	return this->y;
}

void Bullet::setX(int x){
	this->x = x;
}
void Bullet::setY(int y){
	this->y = y;
}