#pragma once
#include "Actor.h"

class Weapon;
class ShotGun;
class Player :
	public Actor
{
	private:
		// stuff
		Weapon* currentWep = nullptr;


	protected:
		// stuff

	public:
		Player();
		virtual ~Player();
		void setBody(b2Body* _body);
		virtual Actor* EmptyClone();
		b2Body* GetBody();
		Weapon* GetCurrentWeapon();

};
