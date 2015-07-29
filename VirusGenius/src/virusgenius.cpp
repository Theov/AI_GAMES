#include "virusgenius.h"

const QString VirusGenius::imageBlackPath = ":/VirusGenius/black.png";
const QString VirusGenius::imageWhitePath = ":/VirusGenius/white.png";
const QString VirusGenius::imageEmptyPath = ":/VirusGenius/empty.png";

VirusGenius::VirusGenius(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	initializeController();
	synchronizeGUI();
}

VirusGenius::~VirusGenius()
{
	delete virusController;
}

void VirusGenius::changeCaseImage(int x, int y, QString Image)
{
	QImage img;
	QString pathOfImageToLoad;

	if (Image == "black")
		pathOfImageToLoad = imageBlackPath;
	else if (Image == "white")
		pathOfImageToLoad = imageWhitePath;
	else
		pathOfImageToLoad = imageEmptyPath;

	img.load(pathOfImageToLoad);

	QLabel* lab = (QLabel*) ui.gridLayout->itemAtPosition(x, y)->widget();
	lab->setPixmap(QPixmap::fromImage(img));
	lab->setFixedWidth(img.width());
	lab->setFixedHeight(img.height());
}

void VirusGenius::initializeController()
{
	if (!virusController)
	{
		delete virusController;
		virusController = new controller();
	}
	else
	{
		virusController = new controller();
	}
}

void VirusGenius::synchronizeGUI()
{
	actualizeBoard();
}

void VirusGenius::actualizeBoard()
{
	for (int i = 0; i < BOARD_DIM; i++)
	{
		for (int j = 0; j < BOARD_DIM; j++)
		{
			changeCaseImage(i, j, virusController->env()->cases().at(i).at(j)->actualSymbole());
		}
	}
}

void VirusGenius::labelClicked()
{
	if (virusController->env()->cases().at(0).at(1)->actualSymbole() == "white")
		virusController->env()->cases().at(0).at(1)->fill("black");
	else
		virusController->env()->cases().at(0).at(1)->fill("white");
	
	synchronizeGUI();
}
