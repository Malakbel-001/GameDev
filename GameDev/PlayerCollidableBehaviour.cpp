#include "PlayerCollidableBehaviour.h"


PlayerCollidableBehaviour::PlayerCollidableBehaviour()
{
}


PlayerCollidableBehaviour::~PlayerCollidableBehaviour()
{
}
void PlayerCollidableBehaviour::Hit(int dmg){
	ent->SetHealt(ent->GetHealt() - dmg);
	//TODO different sound
	SoundBank::GetInstance()->Play(SoundEffectType::CORRECT, 60);

}
CollidableBehaviour* PlayerCollidableBehaviour::EmptyClone(){
	return new PlayerCollidableBehaviour();
}