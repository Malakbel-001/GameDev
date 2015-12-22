#pragma once
#include "Player.h"
class Vehicle :
	public Player
{
public:
	Vehicle();
	~Vehicle();

	void SetPassenger(Object* _passenger);
	Object* GetPassenger();

	void Shoot() override;

private:
	Object* passenger;
};

