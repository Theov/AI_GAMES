#ifndef GENIUS_H
#define GENIUS_H

#include "environement.h"

class genius
{
public:
	genius(environement* env);
	~genius();

	void play();

private:
	environement* nimEnvironement;
	int binaryMatrix[5][4];

private:
	void initializeMatrix();
	void actualizeBynaryMatrix();
	bool doesSituationIsSafe();
};

#endif