#pragma once
#include "Actor.h"


class Player :
	public Actor
{
	private:
		// stuff
		
		int currentwep;
		vector<Weapon*> weps;
	protected:
		// stuff
		
		//in constructor
	
	public:
		Player();
		virtual ~Player();
		void setBody(b2Body* _body);
		virtual Actor* EmptyClone();
		b2Body* GetBody();
		virtual void AddWeapon(Weapon* wep);
		virtual Weapon* GetCurrentWeapon();
		bool ContainsWeapons();
		void DeleteWeapons();
		virtual void SwitchWeapon(int x);
};
