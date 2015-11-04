#include "Entity.h"
#include <iostream>
Entity::Entity()
{
	
}
void Entity::Init(b2Body* _body, float _width, float _height, EntityType _type, BehaviourFactory* bf, DrawableContainer* drawContainer){
	type = _type;
	body = _body;
	width = _width;
	height = _height;
	draw = bf->CreateDrawableBehaviour(type);
	draw->SetEntity(this);
	drawContainer->Add(draw);

}

int Entity::GetWidth()
{
	return width;
}

int Entity::GetHeight()
{
	return height;
}

int Entity::GetXPos()
{
	return body->GetPosition().x;
}

int Entity::GetYPos()
{
	return body->GetPosition().y;
}

 Entity* Entity::EmptyClone(){
	 std::cout << "entity";
	return new Entity();
}
Entity::~Entity()
{
	
}
