#include "Acorn.h"


Acorn::Acorn()
{
}


Acorn::~Acorn()
{
}

Acorn* Acorn::EmptyClone(){
	return new Acorn();
}

void Acorn::SetBody(b2Body* _body)
{
	body = _body;
}

b2Body* Acorn::GetBody()
{
	return body;
}