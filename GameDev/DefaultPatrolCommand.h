#pragma once
#include "BaseCommand.h"
class DefaultPatrolCommand :
	public BaseCommand
{
public:
	DefaultPatrolCommand();
	~DefaultPatrolCommand();

	virtual void Execute(Actor* actor) override;
};

