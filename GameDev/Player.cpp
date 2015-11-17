#include "Player.h"

Player::Player() { }

Player::~Player() { }

Entity* Player::EmptyClone()
{
	return new Player();
}
void Player::setBody(b2Body* _body)
{
	body = _body;
}

b2Body* Player::GetBody()
{
	return body;
}

void Player::HandleKeyEvents(SDL_Keycode _code)
{
	b2Vec2 vel = GetBody()->GetLinearVelocity();

	bool jump = false; // (GetBody()->GetLinearVelocity().y > 0);

	float x = vel.x;
	float y = vel.y;
	float impulse;
	switch (_code)
	{
		case SDLK_w:
			if (GetBody()->GetLinearVelocity().y > 0)
			{
				jump = true;
				impulse = 100;
				SoundBank::GetInstance()->Play(SoundEffectType::CORRECT);
				GetBody()->ApplyLinearImpulse(b2Vec2(0, -impulse), GetBody()->GetWorldCenter(), true);

				if (GetEntityState() < EntityState::EndLeftMovement)
					SetEntityState(EntityState::JumpLeft);
				else
					SetEntityState(EntityState::JumpRight);
			}
			break;
		case SDLK_a:
			x = -5;
			if (!jump)
				SetEntityState(EntityState::WalkRight);
			else
				SetEntityState(EntityState::JumpRightMove);
			break;
		case SDLK_s:
			y = 5;
			if (jump)
			{
				if (GetEntityState() < EntityState::EndLeftMovement)
					SetEntityState(EntityState::CrouchLeft);
				else
					SetEntityState(EntityState::CrouchRight);
			}
			break;
		case SDLK_d:
			x = 5;
			if (!jump)
				SetEntityState(EntityState::WalkLeft);
			else
				SetEntityState(EntityState::JumpLeftMove);
			break;
	}

	if (!jump)
	{
		vel.Set(x, y);
		GetBody()->SetLinearVelocity(vel);
	}
}
