#include "slot.h"


slot::slot()
{
	symbole = "empty";
}


slot::~slot()
{
}

bool slot::isEmpty()
{
	return symbole == "empty";
}

QString slot::actualSymbole()
{
	return symbole;
}

void slot::fill(QString fillingSymbole)
{
	if (isEmpty())
		symbole = fillingSymbole;
}
