#ifndef VIRUSGENIUS_H
#define VIRUSGENIUS_H

#include <QtWidgets/QMainWindow>
#include "ui_virusgenius.h"

#include "controller.h"

#define BOARD_DIM 7

class VirusGenius : public QMainWindow
{
	Q_OBJECT

public:
	VirusGenius(QWidget *parent = 0);
	~VirusGenius();

private:
	void changeCaseImage(int x, int y, QString Image);
	void initializeController();
	void synchronizeGUI();
	void actualizeBoard();

private:
	Ui::VirusGeniusClass ui;
	controller* virusController;

	static const QString imageBlackPath;
	static const QString imageWhitePath;
	static const QString imageEmptyPath;

private slots:
	void labelClicked();
};

#endif // VIRUSGENIUS_H
