#ifndef VIRUSGENIUS_H
#define VIRUSGENIUS_H

#include <QtWidgets/QMainWindow>
#include "ui_virusgenius.h"

class VirusGenius : public QMainWindow
{
	Q_OBJECT

public:
	VirusGenius(QWidget *parent = 0);
	~VirusGenius();

private:
	Ui::VirusGeniusClass ui;
};

#endif // VIRUSGENIUS_H
