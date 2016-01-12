#include "NpcStatsContainer.h"

NpcStatsContainer::NpcStatsContainer(int _hitdmg, int _health, int _score, float _height, float _width) 
	: EntityStatsContainer(_height, _width) {

	hitdmg = _hitdmg;
	health = _health;
	score = _score;
}

NpcStatsContainer::~NpcStatsContainer() {

}

int NpcStatsContainer::GetHitDmg() {
	return hitdmg;
}
int NpcStatsContainer::GetHealth() {
	return health;
}
int NpcStatsContainer::GetScore() {
	return score;
}