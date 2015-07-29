#include "virusgenius.h"

VirusGenius::VirusGenius(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	virusController = new controller();

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			changeCaseImage(i, j, virusController->env()->cases().at(i).at(j)->actualSymbole());
		}
	}
}

VirusGenius::~VirusGenius()
{

}

void VirusGenius::changeCaseImage(int x, int y, QString Image)
{
	QImage img;
	QString pathOfImageToLoad;

	if (Image == "black")
	{
		pathOfImageToLoad = ":/VirusGenius/black.png";
	}
	else if (Image == "white")
	{
		pathOfImageToLoad = ":/VirusGenius/white.png";
	}
	else
	{
		pathOfImageToLoad = ":/VirusGenius/empty.png";
	}

	img.load(pathOfImageToLoad);

	QLabel* lab = (QLabel*) ui.gridLayout->itemAtPosition(x, y)->widget();
	lab->setPixmap(QPixmap::fromImage(img));
	lab->setFixedWidth(img.width());
	lab->setFixedHeight(img.height());
}
