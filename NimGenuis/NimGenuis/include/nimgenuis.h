#ifndef NIMGENUIS_H
#define NIMGENUIS_H

#include <QtWidgets/QMainWindow>
#include "ui_nimgenuis.h"
#include "controller.h"

#include <QPainter>

class NimGenuis : public QMainWindow
{
	Q_OBJECT

public:
	NimGenuis(QWidget *parent = 0);
	~NimGenuis();

private:
	void synchronizeGUI();
	void synchronizeLogLabel();
	void synchronizeStacksLabel();
	void synchronizeOneStackLabel(int numberOfTheStackToSynchronize);
	void initializeGUI();
	void initializeController();
	void freezeControlGUI(bool yesOrNo);
	void uncheckedRadios();

private:
	Ui::NimGenuisClass ui;
	controller* nimController;

	const static QString matchesImagePath;
	const static QString scientistHelloImagePath;
	const static QString scientistThinkImagePath;
	const static QString scientistIdeaImagePath;
	const static QString scientistFrogImagePath;
	const static QString scientistNormalImagePath;


public slots:
	void launchGameClicked();
	void stackOneChosen();
	void stackTwoChosen();
	void stackThreeChosen();
	void stackFourChosen();
	void update();
	void getHumaneAction();
	void displayRules();
	void changeScientist(QString);

signals:
	void sendHumaneAction(int, int);
};

#endif // NIMGENUIS_H
