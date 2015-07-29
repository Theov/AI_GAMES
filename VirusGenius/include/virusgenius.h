#ifndef VIRUSGENIUS_H
#define VIRUSGENIUS_H

#include <QtWidgets/QMainWindow>
#include "ui_virusgenius.h"

#include "controller.h"

class VirusGenius : public QMainWindow
{
	Q_OBJECT

public:
	VirusGenius(QWidget *parent = 0);
	~VirusGenius();

private:
	void changeCaseImage(int x, int y, QString Image);

private:
	Ui::VirusGeniusClass ui;
	controller* virusController;
};

#endif // VIRUSGENIUS_H
