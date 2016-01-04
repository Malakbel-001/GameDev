#pragma once

class Actor;
class BaseCommand
{
public:
	BaseCommand();
	~BaseCommand();

	virtual void Execute(Actor* actor) = 0;
};

