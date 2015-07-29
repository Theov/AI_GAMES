#ifndef ENVIRONEMENT_H
#define ENVIRONEMENT_H

#include "stack.h"
#include <QList>

class environement
{
public:
	environement();
	~environement();

	QList<stack *> envStacks();

private:
	void initializeStacks();
	QList<stack *> Stacks;
};

#endif

