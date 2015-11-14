#include "Bullet.h"


Bullet::Bullet()
{
}

Actor* Bullet::EmptyClone(){
	return new Bullet();
}

Bullet::~Bullet()
{
}

void Bullet::setBody(b2Body* _body)
{
	body = _body;
}

b2Body* Bullet::GetBody()
{
	return body;
}