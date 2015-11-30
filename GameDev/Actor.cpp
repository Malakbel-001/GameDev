#include "Actor.h"
#include "Weapon.h"
Actor::Actor()
{
	
	dead = false;
}


void Actor::InitActor(b2Body* _body, int _hitdmg, int _health, float _width, float _height, EntityType _type, BehaviourFactory* bf, DrawableContainer* drawContainer){
	Init(_body, _width, _height, _type, bf, drawContainer);
	hitdmg = _hitdmg;
	health = _health;
	maxHealth = _health; //NEW
	col = bf->CreateCollidableBehaviour(type);
	col->Init(this);
	//jumpsensor = bf->CreateCollidableBehaviour(EntityType::JUMP);
//	jumpsensor->Init(this);
///	body->GetFixtureList()->SetUserData(jumpsensor);
	body->SetUserData(col);

	//direction = b2Vec2(0, 0);
	m_jumpTimeout = 0;

}
Actor* Actor::EmptyClone(){

	return new Actor();
}

Actor::~Actor()
{
}

int Actor::GetNumFootContacts(){
	return numFootContacts;
}
void Actor::SetNumFootContacts(int x){
	numFootContacts = x;
}


void Actor::SetHealth(int _health){

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
int Actor::GetHealth(){
	return health;
}
int Actor::GetMaxHealth() {
	return maxHealth;
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

int Actor::GetJumpTimeOut(){
	return m_jumpTimeout;
}	

void Actor::SetJumpTimeOut(int _m_jumpTimeout){
	m_jumpTimeout = _m_jumpTimeout;
}

Weapon* Actor::GetCurrentWeapon(){

	return currentWep;

}
