#include "Entity.h"
#include <iostream>


Entity::Entity()
{
	
}
void Entity::Init(b2Body* _body, float _width, float _height, EntityType _type, BehaviourFactory* bf, DrawableContainer* drawContainer)
{
	Object::Init(_type, bf,drawContainer);
	body = _body;
	width = _width;
	height = _height;
	
	
}

Entity::~Entity()
{
	
	printf("a");

}

int Entity::GetWidth()
{
	return static_cast<int>(width);
}

int Entity::GetHeight()
{
	return static_cast<int>(height);
}

float Entity::GetXpos()
{
	return (body->GetPosition().x);
}

float Entity::GetYpos()
{
	return (body->GetPosition().y);

}

float Entity::GetAngle(){
	return body->GetAngle();
}

Entity* Entity::EmptyClone()
{
	std::cout << "entity";
	return new Entity();
}
b2Body* Entity::GetBody(){
	return body;
}
