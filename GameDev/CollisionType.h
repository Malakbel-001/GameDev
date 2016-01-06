#pragma once
#include "Box2D\Box2D.h"

enum class CollisionType {
	OTHER =				0x0001,
	ALLYBULLET =		0x0002,
	ENEMYBULLET =		0x0004,
	ALLY =				0x0008,
	ENEMY =				0x0010,
};