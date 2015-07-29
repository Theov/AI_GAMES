#include "controller.h"


controller::controller()
{
	virusEnvironement = new environement();
}


controller::~controller()
{
	delete virusEnvironement;
}

environement* controller::env()
{
	return virusEnvironement;
}