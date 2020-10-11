#include "ListOfSmartPhones.h"
#include<iostream>
#include<cstring>

using namespace std;

void ListOfSmartPhones::setSize(const int Size)
{
	this->Size = Size;
}

void ListOfSmartPhones::setMaxSize(const int maxSize)
{
	this->MaxSize = maxSize;
}

void ListOfSmartPhones::resize()
{
	this->MaxSize *= 2;
	SmartPhone* temp = new SmartPhone[this->MaxSize];
	for (int i = 0; i < this->Size; i++) {
		temp[i] = this->SmartPhones[i];
	}
	delete[] SmartPhones;
	SmartPhones = temp;
}

void ListOfSmartPhones::shrink()
{
	this->MaxSize /= 2;
	SmartPhone* temp = new SmartPhone[this->MaxSize];
	for (int i = 0; i < this->Size; i++) {
		temp[i] = this->SmartPhones[i];
	}
	delete[] SmartPhones;
	SmartPhones = temp;
}

ListOfSmartPhones::ListOfSmartPhones()
{
	setSize(0);
	setMaxSize(1);
	this->SmartPhones = new SmartPhone[this->MaxSize];
}

ListOfSmartPhones::ListOfSmartPhones(const int maxSize)
{
	setSize(0);
	setMaxSize(maxSize);
	this->SmartPhones = new SmartPhone[this->MaxSize];
}

ListOfSmartPhones::ListOfSmartPhones(const ListOfSmartPhones & copy)
{
	setSize(copy.Size);
	setMaxSize(copy.MaxSize);
	this->SmartPhones = new SmartPhone[this->MaxSize];
	for (int i = 0; i < this->Size; i++) {
		this->SmartPhones[i] = copy.SmartPhones[i];
	}
}

const ListOfSmartPhones & ListOfSmartPhones::operator=(const ListOfSmartPhones & copy)
{
	if (this != &copy) {
		setSize(copy.Size);
		setMaxSize(copy.MaxSize);
		delete[] SmartPhones;
		SmartPhones = nullptr;
		this->SmartPhones = new SmartPhone[this->MaxSize];
		for (int i = 0; i < this->Size; i++) {
			this->SmartPhones[i] = copy.SmartPhones[i];
		}
	}
	return *this;
}

const int ListOfSmartPhones::getSize() const
{
	return Size;
}

const int ListOfSmartPhones::getMaxSize() const
{
	return MaxSize;
}

void ListOfSmartPhones::addSmartPhone(const SmartPhone & newSmartPhone)
{
	for (int i = 0; i < this->Size; i++) {
		if (strcmp(newSmartPhone.getModel(),SmartPhones[i].getModel())==0) {
			cout << "This SmartPhone is already in the ListOfSmartPhones" << endl;
		}
	}
	if (this->Size == this->MaxSize) {
		resize();
	}
	SmartPhones[this->Size] = newSmartPhone;
	this->Size++;
}

void ListOfSmartPhones::removeSmartPhone(const SmartPhone & SmartPhone)
{
	for (int i = 0; i < this->Size; i++) {
		if (strcmp(SmartPhone.getModel(), SmartPhones[i].getModel()) == 0) {
			removeSmartPhoneWithIndex(i);
			return;
		}
	}
}

void ListOfSmartPhones::removeSmartPhoneWithIndex(const int index)
{
	if (index == this->Size) {
		this->Size--;
		return;
	}
	for (int i = index; i < this->Size - 1; i++) {
		SmartPhones[i] = SmartPhones[i + 1];
	}
	this->Size--;
	if (4 * Size <= MaxSize) shrink();
}

void ListOfSmartPhones::printAllSmartPhones() const
{
	if (this->Size == 0) {
		cout << "The cart is empty!" << endl;
		return;
	}
	for (int i = 0; i < this->Size; i++) {
		SmartPhones[i].print();
	}
}

const double ListOfSmartPhones::calculate() const
{
	double bill = 0;
	for (int i = 0; i < this->Size; i++) {
		bill += this->SmartPhones[i].getPrice();
	}
	return bill;
}

ListOfSmartPhones::~ListOfSmartPhones()
{
	delete[] SmartPhones;
	SmartPhones = nullptr;
}
