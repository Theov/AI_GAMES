#include "..\include\stack.h"


stack::stack(int initialNumberOfMatches)
{
	numberOfMatches = initialNumberOfMatches;
}


stack::~stack()
{
}

bool stack::isEmpty()
{
	return numberOfMatches <= 0;
}

int stack::numberOfMatchesRemaining()
{
	return numberOfMatches;
}

void stack::takeNMatches(int numberOfMatchesToTake)
{
	if (numberOfMatchesToTake >= numberOfMatches)
	{
		numberOfMatches = 0;
	}
	else
	{
		numberOfMatches -= numberOfMatchesToTake;
	}
}

void stack::putNMatches(int numberOfMatchesToPut)
{
	numberOfMatches += numberOfMatchesToPut;
}