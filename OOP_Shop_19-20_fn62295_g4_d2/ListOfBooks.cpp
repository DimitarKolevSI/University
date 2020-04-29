#include "ListOfBooks.h"
#include<iostream>
#include<cstring>

using namespace std;

void ListOfBooks::setSize(const int Size)
{
	this->Size = Size;
}

void ListOfBooks::setMaxSize(const int maxSize)
{
	this->MaxSize = maxSize;
}

void ListOfBooks::resize()
{
	this->MaxSize *= 2;
	Book* temp = new Book[this->MaxSize];
	for (int i = 0; i < this->Size; i++) {
		temp[i] = this->Books[i];
	}
	delete[] Books;
	Books = temp;
}

void ListOfBooks::shrink()
{
	this->MaxSize /= 2;
	Book* temp = new Book[this->MaxSize];
	for (int i = 0; i < this->Size; i++) {
		temp[i] = this->Books[i];
	}
	delete[] Books;
	Books = temp;
}

ListOfBooks::ListOfBooks()
{
	setSize(0);
	setMaxSize(1);
	this->Books = new Book[this->MaxSize];
}

ListOfBooks::ListOfBooks(const int maxSize)
{
	setSize(0);
	setMaxSize(maxSize);
	this->Books = new Book[this->MaxSize];
}

ListOfBooks::ListOfBooks(const ListOfBooks & copy)
{
	setSize(copy.Size);
	setMaxSize(copy.MaxSize);
	this->Books = new Book[this->MaxSize];
	for (int i = 0; i < this->Size; i++) {
		this->Books[i] = copy.Books[i];
	}
}

const ListOfBooks & ListOfBooks::operator=(const ListOfBooks & copy)
{
	if (this != &copy) {
		setSize(copy.Size);
		setMaxSize(copy.MaxSize);
		delete[] Books;
		Books = nullptr;
		this->Books = new Book[this->MaxSize];
		for (int i = 0; i < this->Size; i++) {
			this->Books[i] = copy.Books[i];
		}
	}
	return *this;
}

const int ListOfBooks::getSize() const
{
	return Size;
}

const int ListOfBooks::getMaxSize() const
{
	return MaxSize;
}

void ListOfBooks::addBook(const Book & newBook)
{
	for (int i = 0; i < this->Size; i++) {
		if (strcmp(newBook.getTitle(),Books[i].getTitle())==0) {
			cout << "This Book is already in the ListOfBooks" << endl;
		}
	}
	if (this->Size == this->MaxSize) {
		resize();
	}
	Books[this->Size] = newBook;
	this->Size++;
}

void ListOfBooks::removeBook(const Book & Book)
{
	for (int i = 0; i < this->Size; i++) {
		if (strcmp(Book.getTitle(), Books[i].getTitle()) == 0) {
			removeBookWithIndex(i);
			return;
		}
	}
}

void ListOfBooks::removeBookWithIndex(const int index)
{
	if (index == this->Size) {
		this->Size--;
		return;
	}
	for (int i = index; i < this->Size - 1; i++) {
		Books[i] = Books[i + 1];
	}
	this->Size--;
	if (4 * Size <= MaxSize) shrink();
}

void ListOfBooks::printAllBooks() const
{
	if (this->Size == 0) {
		cout << "The cart is empty!" << endl;
		return;
	}
	for (int i = 0; i < this->Size; i++) {
		Books[i].print();
	}
}

const double ListOfBooks::calculate() const
{
	double bill = 0;
	for (int i = 0; i < this->Size; i++) {
		bill += this->Books[i].getPrice();
	}
	return bill;
}

ListOfBooks::~ListOfBooks()
{
	delete[] Books;
	Books = nullptr;
}
