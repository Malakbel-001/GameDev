#include "Bullet.h"


Bullet::Bullet()
{
}

Bullet* Bullet::EmptyClone(){
	return new Bullet();
}

Bullet::~Bullet()
{
	
}



void Bullet::SetBody(b2Body* _body)
{
	body = _body;
}

b2Body* Bullet::GetBody()
{
	return body;
}