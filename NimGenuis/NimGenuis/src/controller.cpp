#include "controller.h"

controller::controller()
{
	nimEnvironement = new environement();
	nimGenuis = new genius(nimEnvironement);

	gameState = "";
	gameCanContinue = false;
	humanePlayerHasPlayed = false;
	currentTurn = 0;
}

controller::~controller()
{
	delete nimGenuis;
	delete nimEnvironement;
}

void controller::launchGame()
{
	currentTurn = 0;
	gameCanContinue = true;
	log("Tu joue en premier le nul", "normal");

	QFuture<void> future = QtConcurrent::run(this, &controller::game);
}

void controller::game()
{
	while (gameCanContinue)
	{
		playTurn();
	}
}

void controller::playTurn()
{
	if (currentTurn % 2 == 0)
	{
		log("A toi le nul", "normal");
		humanPlayerTurn();
	}
	else
	{
		log("A moi ...", "think");
		Sleep(800);

		log("J'ai trouvé !", "idea");
		genuisTurn();
		Sleep(800);
		
		log("A toi le nul", "normal");
	}
	
	checkForGameEnd();
	emit(updateGUI());
	currentTurn++;
}

void controller::genuisTurn()
{
	nimGenuis->play();
}

void controller::humanPlayerTurn()
{
	while (!humanePlayerHasPlayed)
	{
		Sleep(25);
	}

	humanePlayerHasPlayed = false;
}

void controller::humanePlay(int stackIndex, int numberOfMatches)
{
	nimEnvironement->envStacks().at(stackIndex)->takeNMatches(numberOfMatches);
	humanePlayerHasPlayed = true;
}

void controller::checkForGameEnd()
{
	gameCanContinue = false;

	for each (stack* oneStack in nimEnvironement->envStacks())
	{
		if (!oneStack->isEmpty())
			gameCanContinue = true;
	}

	if (!gameCanContinue)
	{
		QString labelOfGameEnd = "Partie fini !";
		QString imageOfGameEnd = "Hello";

		if (currentTurn % 2 == 0)
		{
			labelOfGameEnd += " Vous avez gagné !";
		}
		else
		{
			labelOfGameEnd += " C'est encore moi qui gagne nullos !";
			imageOfGameEnd = "frog";
		}

		log(labelOfGameEnd, imageOfGameEnd);
	}
}

void controller::log(QString message, QString image)
{
	gameState = message;
	emit(changeImage(image));
	emit(updateGUI());
}

environement* controller::env()
{
	return nimEnvironement;
}

QString controller::state()
{
	return gameState.toLatin1();
}