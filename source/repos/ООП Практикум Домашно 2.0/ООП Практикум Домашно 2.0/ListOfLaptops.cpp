#include "ListOfLaptops.h"
#include<iostream>

using namespace std;

void ListOfLaptops::setSize(const int Size)
{
	this->Size = Size;
}

void ListOfLaptops::setMaxSize(const int maxSize)
{
	this->MaxSize = maxSize;
}

void ListOfLaptops::resize()
{
	this->MaxSize *= 2;
	Laptop* temp = new Laptop[this->MaxSize];
	for (int i = 0; i < this->Size; i++) {
		temp[i] = this->Laptops[i];
	}
	delete[] Laptops;
	Laptops = temp;
}

void ListOfLaptops::shrink()
{
	this->MaxSize /= 2;
	Laptop* temp = new Laptop[this->MaxSize];
	for (int i = 0; i < this->Size; i++) {
		temp[i] = this->Laptops[i];
	}
	delete[] Laptops;
	Laptops = temp;
}

ListOfLaptops::ListOfLaptops()
{
	setSize(0);
	setMaxSize(1);
	this->Laptops = new Laptop[this->MaxSize];
}

ListOfLaptops::ListOfLaptops(const int maxSize)
{
	setSize(0);
	setMaxSize(maxSize);
	this->Laptops = new Laptop[this->MaxSize];
}

ListOfLaptops::ListOfLaptops(const ListOfLaptops & copy)
{
	setSize(copy.Size);
	setMaxSize(copy.MaxSize);
	this->Laptops = new Laptop[this->MaxSize];
	for (int i = 0; i < this->Size; i++) {
		this->Laptops[i] = copy.Laptops[i];
	}
}

const ListOfLaptops & ListOfLaptops::operator=(const ListOfLaptops & copy)
{
	if (this != &copy) {
		setSize(copy.Size);
		setMaxSize(copy.MaxSize);
		delete[] Laptops;
		Laptops = nullptr;
		this->Laptops = new Laptop[this->MaxSize];
		for (int i = 0; i < this->Size; i++) {
			this->Laptops[i] = copy.Laptops[i];
		}
	}
	return *this;
}

const int ListOfLaptops::getSize() const
{
	return Size;
}

const int ListOfLaptops::getMaxSize() const
{
	return MaxSize;
}

void ListOfLaptops::addLaptop(const Laptop & newLaptop)
{
	for (int i = 0; i < this->Size; i++) {
		if (newLaptop.getModel() == Laptops[i].getModel()) {
			cout << "This Laptop is already in the ListOfLaptops" << endl;
		}
	}
	if (this->Size == this->MaxSize) {
		resize();
	}
	Laptops[this->Size] = newLaptop;
	this->Size++;
}

void ListOfLaptops::removeLaptop(const Laptop & Laptop)
{
	for (int i = 0; i < this->Size; i++) {
		if (Laptop.getModel() == Laptops[i].getModel()) {
			removeLaptopWithIndex(i);
			return;
		}
	}
}

void ListOfLaptops::removeLaptopWithIndex(const int index)
{
	if (index == this->Size) {
		this->Size--;
		return;
	}
	for (int i = index; i < this->Size - 1; i++) {
		Laptops[i] = Laptops[i + 1];
	}
	this->Size--;
	if (4 * Size <= MaxSize) shrink();
}

void ListOfLaptops::printAllLaptops() const
{
	if (this->Size == 0) {
		cout << "The cart is empty!" << endl;
		return;
	}
	for (int i = 0; i < this->Size; i++) {
		Laptops[i].print();
	}
}

ListOfLaptops::~ListOfLaptops()
{
	delete[] Laptops;
	Laptops = nullptr;
}
