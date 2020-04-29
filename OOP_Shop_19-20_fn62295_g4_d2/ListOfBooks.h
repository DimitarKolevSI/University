#pragma once
#include "Book.h"
class ListOfBooks
{
private:
	Book* Books = nullptr;
	int Size;
	int MaxSize;

	void setSize(const int Size);
	void setMaxSize(const int MaxSize);
	void resize();
	void shrink();
public:
	ListOfBooks();
	ListOfBooks(const int MaxSize);
	ListOfBooks(const ListOfBooks& copy);
	const ListOfBooks& operator=(const ListOfBooks&);

	const int getSize() const;
	const int getMaxSize() const;

	void addBook(const Book& newBook);
	void removeBook(const Book& Book);
	void removeBookWithIndex(const int index);
	void printAllBooks() const;
	const double calculate() const;

	~ListOfBooks();
};