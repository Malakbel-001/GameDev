#include "BareEntity.h"


BareEntity::BareEntity(){
	
}
void BareEntity::Init(float _xpos, float _ypos, float _angle, EntityState _state, EntityType _type, BehaviourFactory* bf, DrawableContainer* drawContainer, MoveableContainer* moveContainer){
	Object::Init(_type, bf, drawContainer, moveContainer);
	
	xpos = _xpos;
	ypos = _ypos;
	angle = _angle;
	state = _state;
}




BareEntity::~BareEntity()
{
}
float BareEntity::GetXpos(){
	return xpos;
}
float BareEntity::GetYpos(){
	return ypos;
}
float BareEntity::GetAngle(){
	return angle;
}
void BareEntity::SetXpos(float _xpos){
	xpos = _xpos;
}
void BareEntity::SetYpos(float _ypos){
	ypos = _ypos;
}
void BareEntity::SetAngle(float _angle){
	angle = _angle;
}
