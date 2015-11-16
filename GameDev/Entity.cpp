#include "Entity.h"
#include <iostream>
Entity::Entity()
{

}
void Entity::Init(b2Body* _body, float _width, float _height, EntityType _type, EntityState _state, BehaviourFactory* bf, DrawableContainer* drawContainer)
{
	type = _type;
	body = _body;
	width = _width;
	height = _height;
	state = _state;
	draw = bf->CreateDrawableBehaviour(type);
	draw->SetEntity(this);
	drawContainer->Add(draw);
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

int Entity::GetXPos()
{
	return static_cast<int>(body->GetPosition().x);
}

int Entity::GetYPos()
{
	return static_cast<int>(body->GetPosition().y);
}

EntityState Entity::GetEntityState()
{
	return this->state;
}

void Entity::SetEntityState(EntityState _state)
{
	this->state = _state;
}

Entity* Entity::EmptyClone()
{
	std::cout << "entity";
	return new Entity();
}
