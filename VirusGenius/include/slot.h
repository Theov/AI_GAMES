#ifndef SLOT_H
#define SLOT_H

#include <QString>

class slot
{
public:
	slot();
	~slot();

	bool isEmpty();
	QString actualSymbole();
	void fill(QString fillingSymbole);

private:
	QString symbole;
	
};

#endif