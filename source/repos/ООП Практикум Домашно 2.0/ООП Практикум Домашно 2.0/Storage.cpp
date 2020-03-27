#include "Storage.h"
#include<iostream>
using namespace std;

void Storage::setSize(const int Size)
{
	this->Size = Size;
}

void Storage::setMaxSize(const int maxSize)
{
	this->MaxSize = maxSize;
}

void Storage::resize()
{
	this->MaxSize *= 2;
	Product* temp = new Product[this->MaxSize];
	for (int i = 0; i < this->Size; i++) {
		temp[i] = this->Products[i];
	}
	delete[] Products;
	Products = temp;
}

void Storage::shrink()
{
	this->MaxSize /= 2;
	Product* temp = new Product[this->MaxSize];
	for (int i = 0; i < this->Size; i++) {
		temp[i] = this->Products[i];
	}
	delete[] Products;
	Products = temp;
}

Storage::Storage()
{
	setSize(0);
	setMaxSize(1);
	this->Products = new Product[this->MaxSize];
}

Storage::Storage(const int maxSize)
{
	setSize(0);
	setMaxSize(maxSize);
	this->Products = new Product[this->MaxSize];
}

Storage::Storage(const Storage & copy)
{
	setSize(copy.Size);
	setMaxSize(copy.MaxSize);
	this->Products = new Product[this->MaxSize];
	for (int i = 0; i < this->Size; i++) {
		this->Products[i] = copy.Products[i];
	}
}

const Storage & Storage::operator=(const Storage & copy)
{
	if (this != &copy) {
		setSize(copy.Size);
		setMaxSize(copy.MaxSize);
		delete[] Products;
		Products = nullptr;
		this->Products = new Product[this->MaxSize];
		for (int i = 0; i < this->Size; i++) {
			this->Products[i] = copy.Products[i];
		}
	}
	return *this;
}

const int Storage::getSize() const
{
	return Size;
}

const int Storage::getMaxSize() const
{
	return MaxSize;
}

void Storage::addProduct(const Product & newProduct)
{
	for (int i = 0; i < this->Size; i++) {
		if (newProduct.getID() == Products[i].getID()) {
			cout << "This product is already in the Storage" << endl;
		}
	}
	if (this->Size == this->MaxSize) {
		resize();
	}
	Products[this->Size] = newProduct;
	this->Size++;
}

void Storage::removeProduct(const Product & product)
{
	for (int i = 0; i < this->Size; i++) {
		if (product.getID() == Products[i].getID()) {
			removeProductWithIndex(i);
			return;
		}
	}
}

void Storage::removeProductWithIndex(const int index)
{
	if (index == this->Size) {
		this->Size--;
		return;
	}
	for (int i = index; i < this->Size - 1; i++) {
		Products[i] = Products[i + 1];
	}
	this->Size--;
	if (4 * Size <= MaxSize) shrink();
}

void Storage::printAllProducts() const
{
	if (this->Size == 0) {
		cout << "The cart is empty!" << endl;
		return;
	}
	for (int i = 0; i < this->Size; i++) {
		Products[i].print();
	}
}

Storage::~Storage()
{
	delete[] Products;
	Products = nullptr;
}
