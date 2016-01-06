#pragma once
#include "Actor.h"


class Player :
	public Actor
{
	private:
		// stuff
		bool godmode = false;
		int score;
		int currentwep;
		vector<Weapon*> weps;
		vector<Uint32> timeplayed;
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
		void GodMode(bool cheat);
		virtual void SwitchWeapon(int x);

		void DeletePrevProp();

		virtual void SetHealth(int _health);
		void AddScore(int _score);

		int GetScore();

		void AddPlayTime(uint32, uint32);
		vector<Uint32> GetPlayTime();
};
