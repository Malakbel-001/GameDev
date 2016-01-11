#pragma once
#include "BaseCommand.h"

class IdleCommand :
	public BaseCommand
{
public:
	IdleCommand();
	~IdleCommand();

	virtual void Execute(Actor* actor) override;
	virtual BaseCommand* EmptyClone() override;

private:
	int timecounter;
	int timecounter2;
};

