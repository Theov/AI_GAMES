#ifndef ENVIRONEMENT_H
#define ENVIRONEMENT_H

#include "slot.h"
#include <QList>

#define BOARD_DIM 7

class environement
{
public:
	environement();
	~environement();

	QList<QList<slot*>> cases();

private:
	void initializeCases();

private:
	QList<QList<slot*>> caseSlot;
};

#endif