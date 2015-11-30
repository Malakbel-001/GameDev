#include "AttackMoveableBehaviour.h"


AttackMoveableBehaviour::AttackMoveableBehaviour()
{
}


AttackMoveableBehaviour::~AttackMoveableBehaviour()
{
}

AttackMoveableBehaviour* AttackMoveableBehaviour::EmptyClone()
{
	return new AttackMoveableBehaviour(enf);
}

void AttackMoveableBehaviour::Move()
{
	if (entity->GetType() == EntityType::PLANTBOSS)
	{
		Npc* npc = static_cast<Npc*>(entity);


		if (SDL_GetTicks() > npc->GetCurrentWeapon()->GetTimeCounter() + npc->GetCurrentWeapon()->GetAttackSpeed()){


			enf->CreateBullet(npc->GetXPos(), npc->GetYPos(), 5, 5, 20, b2Vec2(1000, 0), EntityType::BULLET);

			npc->GetCurrentWeapon()->SetTimeCounter(SDL_GetTicks());
		}
	}
}