 #include "MoveableBehaviour.h"


MoveableBehaviour::MoveableBehaviour()
{
}


MoveableBehaviour::~MoveableBehaviour()
{
}

//void MoveableBehaviour::SetEntity(Entity* _entity)
//{
//	entity = _entity;
//}

MoveableBehaviour* MoveableBehaviour::EmptyClone()
{
	return new MoveableBehaviour();
}

void MoveableBehaviour::Move()
{

}
