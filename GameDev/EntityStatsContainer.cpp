#include "EntityStatsContainer.h"

EntityStatsContainer::EntityStatsContainer(float _height, float _width) {
	height = _height;
	width = _width;
}

EntityStatsContainer::~EntityStatsContainer() {
	//nothing to destruct
}

float EntityStatsContainer::GetHeight() {
	return height;
}
float EntityStatsContainer::GetWidth() {
	return width;
}