#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "environement.h"
#include "genius.h"
#include "stack.h"

#include <QFuture>
#include <QtConcurrent/QtConcurrentRun>

#include "Windows.h"

class controller : public QObject
{
	Q_OBJECT

public:
	controller();
	~controller();
	environement* env();
	QString state();
	void launchGame();

private:
	void game();
	void playTurn();
	void humanPlayerTurn();
	void genuisTurn();
	void checkForGameEnd();

private:
	environement* nimEnvironement;
	genius* nimGenuis;

	bool gameCanContinue;
	bool humanePlayerHasPlayed;
	QString gameState;
	int currentTurn;
	void log(QString message, QString image);

signals:
	void updateGUI();
	void changeImage(QString);

public slots:
	void humanePlay(int, int);
	
};

#endif

