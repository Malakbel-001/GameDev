#pragma once

class Behaviour
{
public:

	Behaviour();
	virtual ~Behaviour();

	virtual Behaviour* EmptyClone();
};

