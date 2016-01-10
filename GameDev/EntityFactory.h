#pragma once
#include "Entity.h"
#include "Actor.h"
#include "Npc.h"
#include "Player.h"
#include <iostream>
#include <unordered_map>
#include "BehaviourFactory.h"
#include "Ground.h"
#include "Bullet.h"
#include "BareEntity.h"
#include "Weapon.h"
#include "Shotgun.h"
#include "Acorn.h"
#include "NpcStatsContainer.h" //indirectly included EntityStatsContainer
#include "CollisionType.h"
#include "DeleteQueryCallback.h"
#include "CollidableContainer.h"
#include "MoveableContainer.h"

class EntityFactory
{
public:
	EntityFactory(b2World& world, std::vector<Actor*>* _actor,std::vector<Entity*>*_ent,BehaviourFactory* _bf, DrawableContainer* _drawContainer);
	~EntityFactory();
	Entity* CreateEntity(float x, float y, float height, float width, EntityType type);
	Entity* CreateEntity(float x, float y, EntityType type);
	Actor* CreateActor(int _hitdmg, int _healt, float x, float y, float height, float width, EntityType type);
	Actor* CreateActor(float x, float y, EntityType type);
	Player* CreatePlayer(int _hitdmg, int _healt, float x, float y, float height, float width, Player* _player);
	Bullet* CreateBullet(float x, float y, int width, int height, int dmg, b2Vec2 direction, uint16 categoryBits, EntityType type);
	b2Body* CreateActorBody(float x, float y, float height, float width, float den, EntityType type);
	//b2Body* CreateActorBodyRound(float x, float y, float height, float width, float den, EntityType type);
	b2Body* CreateBody(float x, float y, float height, float width, EntityType type);
	Weapon* CreateWeapon(float x, float y, EntityType type);
	b2Body* CreateBody(float x, float y, float height, float width, float den, EntityType type);

	void ClickAndDeleteEntity(float x, float y, DrawableContainer* drawableContainer, MoveableContainer* moveableContainer, CollidableContainer* collidableContainer);
	void DeleteEntity(Entity* entity, DrawableContainer* drawableContainer, MoveableContainer* moveableContainer, CollidableContainer* collidableContainer);

	//Level Editor functions
	std::vector<EntityType>* GetActorTypeList();
	std::vector<EntityType>* GetEntityTypeList();

private:
	DrawableContainer* drawContainer;
	BehaviourFactory* bf;

	std::unordered_map<EntityType, Weapon*> weaponRegistery;
	std::unordered_map<EntityType, Entity*> entityRegistery;
	std::unordered_map<EntityType, Actor*> actorRegistery;
	std::unordered_map<EntityType, b2BodyDef > bodyRegistery;
	std::unordered_map<EntityType, Bullet* > bulletRegistery;

	std::unordered_map<EntityType, NpcStatsContainer*> npcStatsRegistery;
	std::unordered_map<EntityType, EntityStatsContainer*> entityStatsRegistery;
	std::unordered_map<EntityType, float> restitutionRegistery;
	std::unordered_map<EntityType, CollisionType> entityCollisionRegistery;

	b2World& world;
	std::vector<Actor*>* actor;
	std::vector<Entity*>* entities;

	DeleteQueryCallback* deleteQueryCallback;
};

