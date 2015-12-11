 #include "MoveableBehaviour.h"


MoveableBehaviour::MoveableBehaviour()
{
}


MoveableBehaviour::~MoveableBehaviour()
{
}

void MoveableBehaviour::SetEntity(Object* _entity)
{
	entity = _entity;
}

Object* MoveableBehaviour::GetEntity()
{
	return entity;
}

MoveableBehaviour* MoveableBehaviour::EmptyClone()
{
	return new MoveableBehaviour();
}

void MoveableBehaviour::Move(float dt)
{

}
