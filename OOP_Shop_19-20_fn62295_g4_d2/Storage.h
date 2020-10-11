#pragma once
#include "Product.h"

class Storage
{
private:
	Product* Products = nullptr;
	int Size;
	int MaxSize;

	void setSize(const int Size);
	void setMaxSize(const int MaxSize);
	void resize();
	void shrink();
public:
	Storage();
	Storage(const int MaxSize);
	Storage(const Storage& copy);
	const Storage& operator=(const Storage&);

	const int getSize() const;
	const int getMaxSize() const;

	void addProduct(const Product& newProduct);
	void removeProduct(const Product& product);
	void removeProductWithIndex(const int index);
	void printAllProducts() const;
	const double calculate() const;

	~Storage();
};