#pragma once
#include "Laptop.h"
class ListOfLaptops
{
private:
	Laptop* Laptops = nullptr;
	int Size;
	int MaxSize;

	void setSize(const int Size);
	void setMaxSize(const int MaxSize);
	void resize();
	void shrink();
public:
	ListOfLaptops();
	ListOfLaptops(const int MaxSize);
	ListOfLaptops(const ListOfLaptops& copy);
	const ListOfLaptops& operator=(const ListOfLaptops&);

	const int getSize() const;
	const int getMaxSize() const;

	void addLaptop(const Laptop& newLaptop);
	void removeLaptop(const Laptop& Laptop);
	void removeLaptopWithIndex(const int index);
	void printAllLaptops() const;

	~ListOfLaptops();
};