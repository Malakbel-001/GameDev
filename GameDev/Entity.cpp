#include "Entity.h"


Entity::Entity()
{
	
}
void Entity::Init(b2Body* _body){
	body = _body;

}
 Entity* Entity::EmptyClone(){
	return new Entity();
}
Entity::~Entity()
{
	
}
