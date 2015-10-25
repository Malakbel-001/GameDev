#include "Player.h"


Player::Player(DrawableContainer dc, BehaviourFactory bf)
{
	drawableContainer = dc;
	drawableBehaviour = bf.CreateDrawableBehaviour(this, drawableContainer.GetRenderer());
	drawableContainer.Add(drawableBehaviour);
}


Player::~Player()
{
}
