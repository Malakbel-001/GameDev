#include "Entity.h"
#include <iostream>
Entity::Entity()
{
	
}
void Entity::Init(b2Body* _body, float _width, float _height, EntityType _type, BehaviourFactory* bf, DrawableContainer* drawContainer)
{
	type = _type;
	body = _body;
	width = _width;
	height = _height;
	
	draw = bf->CreateDrawableBehaviour(type);
	draw->SetEntity(this);
		
	drawContainer->Add(draw);
	state = EntityState::IDLE;
}

Entity::~Entity()
{

}

int Entity::GetWidth()
{
	return static_cast<int>(width);
}

int Entity::GetHeight()
{
	return static_cast<int>(height);
}

EntityType Entity::GetType(){
	return type;
}
int Entity::GetXPos()
{
	return static_cast<int>(body->GetPosition().x);
}

int Entity::GetYPos()
{
	return static_cast<int>(body->GetPosition().y);

}

void Entity::SetState(EntityState _state)
{
	state = _state; 
}

EntityState Entity::GetState()
{
	return state;
}

Entity* Entity::EmptyClone()
{
	std::cout << "entity";
	return new Entity();
}
b2Body* Entity::GetBody(){
	return body;
}
