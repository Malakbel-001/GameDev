#include "Bullet.h"


Bullet::Bullet()
{
}



Entity* Bullet::EmptyClone()
{
	return new Bullet();
}


Bullet::~Bullet()
{
}
