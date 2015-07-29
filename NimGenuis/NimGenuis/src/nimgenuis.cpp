#include "nimgenuis.h"

const QString NimGenuis::matchesImagePath = ":/NimGenuis/matches.png";
const QString NimGenuis::scientistHelloImagePath = ":/NimGenuis/scientist-hello.png";
const QString NimGenuis::scientistThinkImagePath = ":/NimGenuis/scientist-think.png";
const QString NimGenuis::scientistIdeaImagePath = ":/NimGenuis/scientist-idea.png";
const QString NimGenuis::scientistFrogImagePath = ":/NimGenuis/scientist-frog.png";
const QString NimGenuis::scientistNormalImagePath = ":/NimGenuis/scientist-normal.png";

NimGenuis::NimGenuis(QWidget *parent)
	: QMainWindow(parent)
{
	initializeGUI();
}

NimGenuis::~NimGenuis()
{

}

void NimGenuis::initializeController()
{
	if (!nimController)
	{
		delete nimController;
		nimController = new controller();
	}
	else
	{
		nimController = new controller();
	}

	connect(nimController, SIGNAL(updateGUI()), this, SLOT(update()));
	connect(this, SIGNAL(sendHumaneAction(int, int)), nimController, SLOT(humanePlay(int, int)));
	connect(nimController, SIGNAL(changeImage(QString)), this, SLOT(changeScientist(QString)));
}

void NimGenuis::launchGameClicked()
{
	initializeController();
	synchronizeGUI();
	freezeControlGUI(false);
	nimController->launchGame();
}

void NimGenuis::getHumaneAction()
{
	int stackIndex = 0;

	if (ui.radioTas1->isChecked())
	{
		stackIndex = 0;
	}
	else if (ui.radioTas2->isChecked())
	{
		stackIndex = 1;
	}
	else if (ui.radioTas3->isChecked())
	{
		stackIndex = 2;
	}
	else
	{
		stackIndex = 3;
	}

	emit(sendHumaneAction(stackIndex, ui.spinMatches->value()));
}

void NimGenuis::synchronizeGUI()
{
	synchronizeStacksLabel();
	uncheckedRadios();
}

void NimGenuis::uncheckedRadios()
{
	ui.radioTas1->setAutoExclusive(false);
	ui.radioTas1->setChecked(false);
	ui.radioTas1->setAutoExclusive(true);

	ui.radioTas2->setAutoExclusive(false);
	ui.radioTas2->setChecked(false);
	ui.radioTas2->setAutoExclusive(true);

	ui.radioTas3->setAutoExclusive(false);
	ui.radioTas3->setChecked(false);
	ui.radioTas3->setAutoExclusive(true);

	ui.radioTas4->setAutoExclusive(false);
	ui.radioTas4->setChecked(false);
	ui.radioTas4->setAutoExclusive(true);

	ui.pushEnlever->setEnabled(false);
}

void NimGenuis::synchronizeLogLabel()
{
	ui.label_Log->setText(nimController->state());
}

void NimGenuis::update()
{
	synchronizeGUI();
	synchronizeLogLabel();
}

void NimGenuis::synchronizeStacksLabel()
{
	for (int i = 0; i < 4; i++)
		synchronizeOneStackLabel(i);
}

void NimGenuis::synchronizeOneStackLabel(int numberOfTheStackToSynchronize)
{
	int width = 56;
	int height = 50;

	QPixmap *pixmap = new QPixmap(width, height);
	pixmap->fill(Qt::transparent);
	QPainter *painter = new QPainter(pixmap);
	
	for (int i = 0; i < nimController->env()->envStacks().at(numberOfTheStackToSynchronize)->numberOfMatchesRemaining(); i++)
	{
		painter->drawPixmap((i * 8), 0, 3, 50, QPixmap(matchesImagePath));
	}

	painter->end();

	if (numberOfTheStackToSynchronize == 0)
	{
		ui.label_tas1->setPixmap(*pixmap);
		ui.label_tas1->resize(QSize(width, height));
	}
	else if (numberOfTheStackToSynchronize == 1)
	{
		ui.label_tas2->setPixmap(*pixmap);
		ui.label_tas2->resize(QSize(width, height));
	}
	else if (numberOfTheStackToSynchronize == 2)
	{
		ui.label_tas3->setPixmap(*pixmap);
		ui.label_tas3->resize(QSize(width, height));
	}
	else
	{
		ui.label_tas4->setPixmap(*pixmap);
		ui.label_tas4->resize(QSize(width, height));
	}

	delete pixmap;
	delete painter;
}

void NimGenuis::freezeControlGUI(bool yesOrNo)
{
	yesOrNo = !yesOrNo;

	ui.radioTas1->setEnabled(yesOrNo);
	ui.radioTas2->setEnabled(yesOrNo);
	ui.radioTas3->setEnabled(yesOrNo);
	ui.radioTas4->setEnabled(yesOrNo);
	ui.spinMatches->setEnabled(yesOrNo);
	ui.pushEnlever->setEnabled(yesOrNo);
}

void NimGenuis::stackOneChosen()
{
	ui.spinMatches->setMinimum(0);
	ui.spinMatches->setMaximum(nimController->env()->envStacks().at(0)->numberOfMatchesRemaining());

	ui.pushEnlever->setEnabled(true);
}
void NimGenuis::stackTwoChosen()
{
	ui.spinMatches->setMinimum(0);
	ui.spinMatches->setMaximum(nimController->env()->envStacks().at(1)->numberOfMatchesRemaining());

	ui.pushEnlever->setEnabled(true);
}
void NimGenuis::stackThreeChosen()
{
	ui.spinMatches->setMinimum(0);
	ui.spinMatches->setMaximum(nimController->env()->envStacks().at(2)->numberOfMatchesRemaining());

	ui.pushEnlever->setEnabled(true);
}
void NimGenuis::stackFourChosen()
{
	ui.spinMatches->setMinimum(0);
	ui.spinMatches->setMaximum(nimController->env()->envStacks().at(3)->numberOfMatchesRemaining());

	ui.pushEnlever->setEnabled(true);
}

void NimGenuis::initializeGUI()
{
	ui.setupUi(this);
	ui.label_tas1->setText("Vide");
	ui.label_tas2->setText("Vide");
	ui.label_tas3->setText("Vide");
	ui.label_tas4->setText("Vide");

	QImage scientistHelloImage;
	scientistHelloImage.load(scientistHelloImagePath);

	ui.label_scientist->setPixmap(QPixmap::fromImage(scientistHelloImage));
	ui.label_scientist->setFixedWidth(scientistHelloImage.width());
	ui.label_scientist->setFixedHeight(scientistHelloImage.height());

	freezeControlGUI(true);

	connect(ui.pushGo, SIGNAL(clicked()), this, SLOT(launchGameClicked()));
	connect(ui.pushEnlever, SIGNAL(clicked()), this, SLOT(getHumaneAction()));
	connect(ui.pushRules, SIGNAL(clicked()), this, SLOT(displayRules()));

	connect(ui.radioTas1, SIGNAL(toggled(bool)), this, SLOT(stackOneChosen()));
	connect(ui.radioTas2, SIGNAL(toggled(bool)), this, SLOT(stackTwoChosen()));
	connect(ui.radioTas3, SIGNAL(toggled(bool)), this, SLOT(stackThreeChosen()));
	connect(ui.radioTas4, SIGNAL(toggled(bool)), this, SLOT(stackFourChosen()));
}

void NimGenuis::displayRules()
{
	QWidget* ruleWindow = new QWidget();
	ruleWindow->show();
	ruleWindow->setWindowTitle(QString::fromLatin1("Régle du jeu du Nim"));
	ruleWindow->setFixedWidth(550);
	ruleWindow->setFixedHeight(80);

	QLabel* label = new QLabel();
	QString rules = QString::fromLatin1("Ce jeu très simple se joue à deux.\n\rOn dispose des paquets d'allumettes sur une table.\n\rChaque joueur, à tour de rôle, prend le nombre d'allumettes qu'il veut (au moins une) dans un des paquets\n\rLe gagnant est celui qui prend la dernière allumette\n\r");
	label->setText(rules);

	QGridLayout* layout = new QGridLayout();
	layout->addWidget(label);
	ruleWindow->setLayout(layout);
}

void NimGenuis::changeScientist(QString imageToLoad)
{
	QImage scientistImage;

	if (imageToLoad == "idea")
	{
		scientistImage.load(scientistIdeaImagePath);
	}
	else if (imageToLoad == "frog")
	{
		scientistImage.load(scientistFrogImagePath);
	}
	else if (imageToLoad == "normal")
	{
		scientistImage.load(scientistNormalImagePath);
	}
	else
	{
		scientistImage.load(scientistThinkImagePath);
	}

	ui.label_scientist->setPixmap(QPixmap::fromImage(scientistImage));
	ui.label_scientist->setFixedWidth(scientistImage.width());
	ui.label_scientist->setFixedHeight(scientistImage.height());
}