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
		int firespeed = 2000;
		
		if (SDL_GetTicks() > timecounter + firespeed && dynamic_cast<Apc*>(actor)->GetTroops().size() < 1){
			b2Vec2 vec = b2Vec2(0, -1000);
			auto passenger = dynamic_cast<Npc*>(actor)->GetFactory()->CreateActor(actor->GetBody()->GetPosition().x * 10, actor->GetBody()->GetPosition().y * 10 + 30, EntityType::MINIGUNNER);
			dynamic_cast<Npc*>(passenger)->SetVehicle(dynamic_cast<Npc*>(actor));
			dynamic_cast<Apc*>(actor)->AddTroops(passenger);

			timecounter = SDL_GetTicks();
		}
	}

	if (actor->GetType() == EntityType::MINIGUNNER)
	{
		int firespeed = 200;

		if (SDL_GetTicks() > timecounter + firespeed){
			b2Vec2 vec = b2Vec2(-1000, 0);

			dynamic_cast<Npc*>(actor)->GetFactory()->CreateBullet(actor->GetBody()->GetWorldCenter().x + vec.x / 200, actor->GetBody()->GetWorldCenter().y + vec.y / 200 + 2, 1, 1, 2, vec, EntityType::BULLET);
			SoundBank::GetInstance()->PlaySFX(SoundEffectType::GUNSHOT);
			timecounter = SDL_GetTicks();
		}
	}
}