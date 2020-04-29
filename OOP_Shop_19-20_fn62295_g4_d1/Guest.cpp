#include "Guest.h"
long long int IDCounter = 1000;
void Guest::setID()
{
	this->ID = IDCounter;
	IDCounter++;
}

Guest::Guest()
{
	setID();
}

const int Guest::getID() const
{
	return this->ID;
}
