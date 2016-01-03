#pragma once
#include "EntityStatsContainer.h"

class NpcStatsContainer : public EntityStatsContainer {
	protected:
		int hitdmg;
		int health;
		int score;
	public:
		NpcStatsContainer(int _hitdmg, int _health, int _score, float _height, float _width);
		~NpcStatsContainer();
		virtual int GetHitDmg();
		virtual int GetHealth();
		virtual int GetScore();
};