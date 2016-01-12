#pragma once
#include "BaseCommand.h"
class SnowBossPatrolCommand :
	public BaseCommand
{
public:
	SnowBossPatrolCommand();
	~SnowBossPatrolCommand();

	virtual void Execute(Actor* actor) override;
	virtual BaseCommand* EmptyClone() override;
};

