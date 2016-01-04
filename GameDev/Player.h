#pragma once
#include "Actor.h"


class Player :
	public Actor
{
	private:
		// stuff
		Player* vehicle;
		int score;
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
		vector<Weapon*> GetWeapons();
		bool ContainsWeapons();
		
		virtual void SwitchWeapon(int x);

		void DeletePrevProp();


		void AddScore(int _score);
		int GetScore();
		
		void SetVehicle(Player* _vehicle);
		Player* GetVehicle();
};
