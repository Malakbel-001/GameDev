#include "Entity.h"
#include <iostream>
Entity::Entity()
{
	
}
void Entity::Init(b2Body* _body, float _width, float _height){
	body = _body;
	width = -_width;
	height = _height;
}
 Entity* Entity::EmptyClone(){
	 std::cout << "entity";
	return new Entity();
}
Entity::~Entity()
{
	
}
