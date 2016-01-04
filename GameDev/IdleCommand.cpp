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

		if (SDL_GetTicks() > timecounter + firespeed){
			b2Vec2 vec = b2Vec2(0, -1000);
			dynamic_cast<Npc*>(actor)->GetFactory()->CreateActor(actor->GetBody()->GetPosition().x, actor->GetBody()->GetPosition().y, EntityType::PLANT);
			timecounter = SDL_GetTicks();
		}
	}
}