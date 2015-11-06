#include "Ground.h"


Ground::Ground()
{
}

Entity* Ground::EmptyClone()
{
	return new Ground();
}

Ground::~Ground()
{
}
