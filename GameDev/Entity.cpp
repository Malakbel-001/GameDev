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
void Entity::HandleEvent(SDL_Event& e)
{
	//If a key was pressed
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
			
		case SDLK_UP: 
			
			
			
			 break;
		case SDLK_DOWN:

		
		 break;
			
			
		
		case SDLK_LEFT: 
		

			
			break;
		case SDLK_RIGHT: 
		
			break;
		}
	}
	//If a key was released
	
}

