#include "Actor.h"

Actor::Actor()
{
	
	dead = false;
}


void Actor::InitActor(b2Body* _body, int _hitdmg, int _health, float _width, float _height, EntityType _type, BehaviourFactory* bf, DrawableContainer* drawContainer){
	Init(_body, _width, _height, _type, bf, drawContainer);
	hitdmg = _hitdmg;
	health = _health;
	col = bf->CreateCollidableBehaviour(type);
	col->Init(this);
	body->SetUserData(col);


}
Actor* Actor::EmptyClone(){

	return new Actor();
}

Actor::~Actor()
{
}

void Actor::SetState(ActorState* new_state)
{
	state = new_state;
}

ActorState* Actor::GetState()
{
	return state;
}
void Actor::SetHealt(int _health){
	if (_health <= 0){
		dead = true;
		health = _health;
	}
	else{
		health = _health;
	}
}
bool Actor::IsDead(){
	return dead;
}
int Actor::GetHealt(){
	return health;
}
int Actor::GetDamage(){
	return hitdmg;
}
b2Vec2 Actor::GetDirection(){
	return direction;
}
void Actor::SetDirection(b2Vec2 dir)
{
	direction = dir;
}
