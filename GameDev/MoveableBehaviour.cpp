#include "MoveableBehaviour.h"

MoveableBehaviour::MoveableBehaviour()
{
	enf = nullptr;
}


MoveableBehaviour::~MoveableBehaviour()
{
}

MoveableBehaviour* MoveableBehaviour::EmptyClone()
{
	return new MoveableBehaviour();
}

void MoveableBehaviour::Move()
{

}

void MoveableBehaviour::SetEntity(Entity* _entity)
{
	entity = _entity;
}

Entity* MoveableBehaviour::GetEntity(){
	return entity;
}

void MoveableBehaviour::SetEntityFactory(EntityFactory* ef)
{
	enf = ef;
}