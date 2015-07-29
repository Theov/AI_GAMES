#include "..\include\environement.h"


environement::environement()
{
	initializeStacks();
}


environement::~environement()
{
	delete Stacks.at(0);
	delete Stacks.at(1);
	delete Stacks.at(2);
	delete Stacks.at(3);
}

void environement::initializeStacks()
{
	Stacks.append(new stack(1));
	Stacks.append(new stack(3));
	Stacks.append(new stack(5));
	Stacks.append(new stack(7));
}

QList<stack *> environement::envStacks()
{
	return Stacks;
}