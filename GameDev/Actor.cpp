#include "Actor.h"
#include "Weapon.h"
#include "StepCollidableBehaviour.h"
#include "SensorCollidableBehaviour.h"
Actor::Actor()
{
	col = nullptr;
	dead = false;	
}


void Actor::InitActor(b2Body* _body, int _hitdmg, int _health, float _width, float _height, EntityType _type, BehaviourFactory* bf, DrawableContainer* drawContainer, MoveableContainer* moveContainer){
	Init(_body, _width, _height, _type, bf, drawContainer, moveContainer);
	
	hitdmg = _hitdmg;
	health = _health;
	maxHealth = _health; //NEW

	height = height / 2;
	width = width / 2;
	float _x = 1;
	float _y = 10;
	float Ratio = _x / _y;
	float newHeight = (height*Ratio);
	float newWidth = (width*Ratio);

	if (col){
		delete col;
	}
	col = bf->CreateCollidableBehaviour(type, this);
	col->Init(this);

	_body->GetFixtureList()->SetUserData(col);

	if (_type == EntityType::PLANT || _type == EntityType::PINGUIN || _type == EntityType::SNOWMAN || _type == EntityType::NPC || _type == EntityType::ENEMY)
	{
		stepLeftSensor = new StepCollidableBehaviour();
		stepLeftSensor->Init(this);

		stepRightSensor = new StepCollidableBehaviour();
		stepRightSensor->Init(this);

		

		b2PolygonShape boxShape;

		//fixture for stepping left
		boxShape.SetAsBox(0.5f, 0.5f, b2Vec2(-2, newHeight + 3), 0);
		b2FixtureDef leftStepDef;
		leftStepDef.shape = &boxShape;
		leftStepDef.isSensor = true;
		auto leftStepFixture = _body->CreateFixture(&leftStepDef);
		leftStepFixture->SetUserData(stepLeftSensor);

		//fixture for stepping right
		boxShape.SetAsBox(0.5f, 0.5f, b2Vec2(newWidth + 2, newHeight + 3), 0);
		b2FixtureDef rightStepDef;
		rightStepDef.shape = &boxShape;
		rightStepDef.isSensor = true;
		auto rightStepFixture = _body->CreateFixture(&rightStepDef);
		rightStepFixture->SetUserData(stepRightSensor);		
	}

	//if (_type == EntityType::PLANTBOSS)
	//{
	//	playerSensor = new SensorCollidableBehaviour();
	//	playerSensor->Init(this);

	//	b2PolygonShape boxShape;
	//	//fixture for detecting player
	//	boxShape.SetAsBox(10, 10);
	//	b2FixtureDef sensorDef;
	//	sensorDef.shape = &boxShape;
	//	sensorDef.isSensor = true;
	//	auto sensorFixture = _body->CreateFixture(&sensorDef);
	//	sensorFixture->SetUserData(playerSensor);
	//}

	//direction = b2Vec2(0, 0);
	m_jumpTimeout = 0;

}
Actor* Actor::EmptyClone(){

	return new Actor();
}

Actor::~Actor()
{
	if (col){
		delete col;
		col = nullptr;
	}
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
	else if (_health > maxHealth) {
		health = maxHealth;
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

CollidableBehaviour* Actor::GetCollidableBehaviour()
{
	return col;
}

CollidableBehaviour* Actor::GetLeftSensorBehaviour()
{
	return stepLeftSensor;
}

CollidableBehaviour* Actor::GetRightSensorBehaviour()
{
	return stepRightSensor;
}

