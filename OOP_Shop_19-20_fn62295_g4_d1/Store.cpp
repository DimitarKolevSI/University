#include "Store.h"
#include <cstring>

void Store::setName(const char * Name)
{
	if (this->Name != nullptr) delete[] this->Name;
	this->Name = new char[strlen(Name) + 1];
	strcpy_s(this->Name, strlen(Name) + 1, Name);
}

Store::Store()
{
	setName("\0");
}

Store::Store(const char * Name)
{
	setName(Name);
}

Store::Store(const Store & copyStore)
{
	setName(copyStore.getName());
}

Store & Store::operator=(const Store & copyStore)
{
	if (this != &copyStore)
	{
		setName(copyStore.getName());
	}
	return *this;
}

const char * Store::getName() const
{
	return this->Name;
}

Store::~Store()
{
	delete[] this->Name;
	this->Name = nullptr;
}
