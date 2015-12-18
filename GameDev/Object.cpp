#include "Object.h"


Object::Object()
{
	draw = nullptr;
	flipped = false;
}
void Object::Init(EntityType _type, BehaviourFactory* bf, DrawableContainer* drawContainer){
	type = _type;
	draw = bf->CreateDrawableBehaviour(type);
	draw->SetEntity(this);

	drawContainer->Add(draw);
	state = EntityState::IDLE;
}

EntityState Object::GetState(){
	return state;
}
void Object::SetState(EntityState _state){
	state = _state;
}
bool Object::ShouldDraw(){
	return shouldDraw;
}
void Object::SetShouldDraw(bool _shoulddraw){
	shouldDraw = _shoulddraw;
}

void Object::SetFlipped(bool _flipped)
{
	flipped = _flipped;
}
bool Object::GetFlipped()
{
	return flipped;
}

EntityType Object::GetType(){
	return type;
}
Object::~Object()
{
	
}
