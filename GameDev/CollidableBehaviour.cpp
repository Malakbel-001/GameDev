#include "CollidableBehaviour.h"


CollidableBehaviour::CollidableBehaviour()
{
}


CollidableBehaviour::~CollidableBehaviour()
{
}

CollidableBehaviour* CollidableBehaviour::EmptyClone()
{
	return new CollidableBehaviour();
}