#pragma once
#include "BaseCommand.h"

class IdleCommand :
	public BaseCommand
{
public:
	IdleCommand();
	~IdleCommand();

	virtual void Execute(Actor* actor) override;
};

