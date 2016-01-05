#include "IdleCommand.h"
#include "Npc.h"
#include "EntityFactory.h"
IdleCommand::IdleCommand()
{
	timecounter = 0;
}


IdleCommand::~IdleCommand()
{
}

void IdleCommand::Execute(Actor* actor)
{	
	if (actor->GetType() == EntityType::APC)
	{
		int firespeed = 800;
		
		if (SDL_GetTicks() > timecounter + firespeed && dynamic_cast<Apc*>(actor)->GetTroopsCount() < 5){
			b2Vec2 vec = b2Vec2(0, -1000);
			dynamic_cast<Npc*>(actor)->GetFactory()->CreateActor(actor->GetBody()->GetPosition().x * 10, actor->GetBody()->GetPosition().y * 10 + 30, EntityType::MINIGUNNER);
			dynamic_cast<Apc*>(actor)->AddTroopsCount();
			timecounter = SDL_GetTicks();
		}
	}

	if (actor->GetType() == EntityType::MINIGUNNER)
	{
		printf("MINIGUNNER executing command");
	}
}