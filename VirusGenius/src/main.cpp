#include "virusgenius.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	VirusGenius w;
	w.show();
	return a.exec();
}
