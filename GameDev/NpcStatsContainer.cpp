#include "NpcStatsContainer.h"

NpcStatsContainer::NpcStatsContainer(int _hitdmg, int _health, int _score, float _height, float _width) {
	hitdmg = _hitdmg;
	health = _health;
	score = _score;
	height = _height;
	width = _width;
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
float NpcStatsContainer::GetHeight() {
	return height;
}
float NpcStatsContainer::GetWidth() {
	return width;
}