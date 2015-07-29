#include "genius.h"

genius::genius(environement* env)
{
	nimEnvironement = env;
	initializeMatrix();
}

void genius::initializeMatrix()
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 4; j++)
			binaryMatrix[i][j] = 0;
}

genius::~genius()
{
}

void genius::play()
{
	/* Actualize Binary Matrix after last human turn */
	actualizeBynaryMatrix();
	bool played = false;

	/* Here we're just try every combinaison for each none empty stack untill ... */
	for each (stack* oneStack in nimEnvironement->envStacks())
	{
		if (!oneStack->isEmpty())
		{
			for (int i = 1; i <= oneStack->numberOfMatchesRemaining(); i++)
			{
				if (!played)
				{
					oneStack->takeNMatches(i);
					actualizeBynaryMatrix();

					/* ... A safe situation is find */
					if (doesSituationIsSafe())
					{
						played = true;
					}
					else
					{
						oneStack->putNMatches(i);
					}
				}
			}
		}

		if (played)
			break;
	}

	// If there's is no more safe situation to play we just take one matches on the first none empty stack found
	if (!played)
	{
		for each (stack* oneStack in nimEnvironement->envStacks())
		{
			if (!oneStack->isEmpty())
			{
				oneStack->takeNMatches(1);
			}
		}
	}
}

bool genius::doesSituationIsSafe()
{
	/* Situation is 'safe' if the last row sum is 0 */
	int binarySum = 0;

	for (int i = 0; i < 4; i++)
	{
		binarySum += binaryMatrix[4][i];
	}

	return binarySum <= 0;
}

void genius::actualizeBynaryMatrix()
{
	QStringList binaryRepresentationList;

	// Cast each stack number of matches in binary
	QString firstStackBinaryRepresentation = QString::number(nimEnvironement->envStacks().at(0)->numberOfMatchesRemaining(), 2);
	QString secondStackBinaryRepresentation = QString::number(nimEnvironement->envStacks().at(1)->numberOfMatchesRemaining(), 2);
	QString thirdStackBinaryRepresentation = QString::number(nimEnvironement->envStacks().at(2)->numberOfMatchesRemaining(), 2);
	QString fourthStackBinaryRepresentation = QString::number(nimEnvironement->envStacks().at(3)->numberOfMatchesRemaining(), 2);

	binaryRepresentationList.append(firstStackBinaryRepresentation);
	binaryRepresentationList.append(secondStackBinaryRepresentation);
	binaryRepresentationList.append(thirdStackBinaryRepresentation);
	binaryRepresentationList.append(fourthStackBinaryRepresentation);

	/* We add 0 to each binary string to match every time the same length */
	for (int i = 0; i < 4; i++)
	{
		if (binaryRepresentationList.at(i).size() < 4)
		{
			QString missingChars;

			for (int j = 0; j < 4 - binaryRepresentationList.at(i).size(); j++)
			{
				missingChars.append("0");
			}

			QString element = binaryRepresentationList.at(i);
			element.prepend(missingChars);

			binaryRepresentationList[i] = element;
		}
	}

	/* The binary conversions are add to the matrix */
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			binaryMatrix[i][j] = (int)binaryRepresentationList.at(i).at(j).digitValue();
		}
	}

	/* The last ROW of the matrix is calculate by doing an XOR of each col */
	for (int i = 0; i < 4; i++)
	{
		int binarySum = 0;

		for (int j = 0; j < 4; j++)
		{
			binarySum += binaryMatrix[j][i];
		}

		if (binarySum % 2 == 0)
		{
			binaryMatrix[4][i] = 0;
		}
		else
		{
			binaryMatrix[4][i] = 1;
		}
	}
}
