#include "Object.h"


Object::Object()
{
	draw = nullptr;
	flipped = false;
}
void Object::Init(EntityType _type, BehaviourFactory* bf, DrawableContainer* drawContainer, MoveableContainer* moveContainer){
	type = _type;
	state = EntityState::IDLE;
	draw = bf->CreateDrawableBehaviour(type);
	draw->SetEntity(this);

	move = bf->CreateMoveableBehaviour(type);
	move->SetEntity(this);

	drawContainer->Add(draw);
	moveContainer->Add(move);	
}

EntityState Object::GetState(){
	return state;
}
void Object::SetState(EntityState _state){
	draw->GetSprite()->SetAnimationSet(_state);
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

DrawableBehaviour* Object::GetDrawableBehaviour()
{
	return draw;
}

void Object::SetDrawableBehaviour(DrawableBehaviour* behaviour)
{

	draw = behaviour;
}


Object::~Object()
{
	//TODO delete stuff
}
