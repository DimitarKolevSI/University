#pragma once
#include "SmartPhone.h"
class ListOfSmartPhones
{
private:
	SmartPhone* SmartPhones = nullptr;
	int Size;
	int MaxSize;

	void setSize(const int Size);
	void setMaxSize(const int MaxSize);
	void resize();
	void shrink();
public:
	ListOfSmartPhones();
	ListOfSmartPhones(const int MaxSize);
	ListOfSmartPhones(const ListOfSmartPhones& copy);
	const ListOfSmartPhones& operator=(const ListOfSmartPhones&);

	const int getSize() const;
	const int getMaxSize() const;

	void addSmartPhone(const SmartPhone& newSmartPhone);
	void removeSmartPhone(const SmartPhone& SmartPhone);
	void removeSmartPhoneWithIndex(const int index);
	void printAllSmartPhones() const;

	~ListOfSmartPhones();
};