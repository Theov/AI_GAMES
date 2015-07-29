#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "environement.h"

class controller
{
public:
	controller();
	~controller();

	environement* env();

private:
	environement* virusEnvironement;
};

#endif

