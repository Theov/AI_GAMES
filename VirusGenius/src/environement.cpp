#include "environement.h"


environement::environement()
{
	initializeCases();
}


environement::~environement()
{
	for (int i = 0; i < BOARD_DIM; i++)
	{
		for (int j = 0; j < BOARD_DIM; j++)
		{
			delete caseSlot.at(i).at(j);
		}
	}
}

void environement::initializeCases()
{
	for (int i = 0; i < BOARD_DIM; i++)
	{
		QList<slot*> tmp;
		
		for (int j = 0; j < BOARD_DIM; j++)
		{
			tmp.append(new slot());
		}

		caseSlot.append(tmp);
	}

	caseSlot.at(0).at(0)->fill("black");
	caseSlot.at(6).at(6)->fill("black");

	caseSlot.at(6).at(0)->fill("white");
	caseSlot.at(0).at(6)->fill("white");
}

QList<QList<slot*>> environement::cases()
{
	return caseSlot;
}
