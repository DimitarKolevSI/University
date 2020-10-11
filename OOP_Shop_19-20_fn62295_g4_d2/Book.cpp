#include "Book.h"
#include <cstring>
#include <iostream>

using namespace std;

void Book::setTitle(const char * Title)
{
	if (this->Title != nullptr) delete[] this->Title;
	this->Title = new char[strlen(Title) + 1];
	strcpy_s(this->Title, strlen(Title) + 1, Title);
}

void Book::setAuthor(const char * Author)
{
	if (this->Author != nullptr) delete[] this->Author;
	this->Author = new char[strlen(Author) + 1];
	strcpy_s(this->Author, strlen(Author) + 1, Author);
}

void Book::setGenre(const char * Genre)
{
	if (this->Genre != nullptr) delete[] this->Genre;
	this->Genre = new char[strlen(Genre) + 1];
	strcpy_s(this->Genre, strlen(Genre) + 1, Genre);
}

void Book::setPages(const int Pages)
{
	this->Pages = Pages;
}

void Book::setPrice(const double Price)
{
	this->Price = Price;
}

void Book::setAmount(const int Amount)
{
	this->Amount = Amount;
}

void Book::setYear(const int Year)
{
	this->Year = Year;
}

void Book::setRating(const double Rating)
{
	this->Rating = Rating;
}

void Book::setNumberOfRatings(const int NumberOfRatings)
{
	this->NumberOfRatings = NumberOfRatings;
}

Book::Book()
{
	setAuthor("\0");
	setTitle("\0");
	setGenre("\0");
	setPrice(0);
	setAmount(0);
	setYear(0);
	setRating(0);
	setNumberOfRatings(0);
}

Book::Book(const char *Title, const char *Author, const char *Genre, const int Pages, const double Price, const int Amount, int Year)
{
	setTitle(Title);
	setAuthor(Author);
	setGenre(Genre);
	setPages(Pages);
	setPrice(Price);
	setAmount(Amount);
	setYear(Year);
	setRating(0);
	setNumberOfRatings(0);
}

Book::Book(const char * Title, const char * Author, const char * Genre, const int Pages, const double Price, const int Amount, const int Year, const double Rating, const int NumberOfRatings)
{
	setTitle(Title);
	setAuthor(Author);
	setGenre(Genre);
	setPages(Pages);
	setPrice(Price);
	setAmount(Amount);
	setYear(Year);
	setRating(Rating);
	setNumberOfRatings(NumberOfRatings);
}

Book::Book(const Book & CopyObject)
{
	setTitle(CopyObject.getTitle());
	setAuthor(CopyObject.getAuthor());
	setGenre(CopyObject.getGenre());
	setPages(CopyObject.getPages());
	setPrice(CopyObject.getPrice());
	setAmount(CopyObject.getAmount());
	setYear(CopyObject.getYear());
	setRating(CopyObject.getRating());
	setNumberOfRatings(CopyObject.getNumberOfRatings());
}

Book & Book::operator=(const Book & CopyObject)
{
	if (this != &CopyObject)
	{
		setTitle(CopyObject.getTitle());
		setAuthor(CopyObject.getAuthor());
		setGenre(CopyObject.getGenre());
		setPages(CopyObject.getPages());
		setPrice(CopyObject.getPrice());
		setAmount(CopyObject.getAmount());
		setYear(CopyObject.getYear());
		setRating(CopyObject.getRating());
		setNumberOfRatings(CopyObject.getNumberOfRatings());
	}
	return *this;
}

const char * Book::getTitle() const
{
	return this->Title;
}

const char * Book::getAuthor() const
{
	return this->Author;
}

const char * Book::getGenre() const
{
	return this->Genre;
}

const int Book::getPages() const
{
	return this->Pages;
}

const double Book::getPrice() const
{
	return this->Price;
}

const int Book::getAmount() const
{
	return this->Amount;
}

const int Book::getYear() const
{
	return this->Year;
}

const double Book::getRating() const
{
	return this->Rating;
}

const int Book::getNumberOfRatings() const
{
	return this->NumberOfRatings;
}

const void Book::print() const
{
	cout << "Title: " << this->Title << endl;
	cout << "Author: " << this->Author << endl;
	cout << "Genre: " << this->Genre << endl;
	cout << "Year: " << this->Year << endl;
	cout << "Price: " << this->Price << endl;
	cout << "Amount: " << this->Amount << endl;
	cout << "Rating: " << this->Rating << "/10 from " << this->NumberOfRatings << " ratings.\n";
}

void Book::decreaseAmount(const int Amount)
{
	if (Amount > this->Amount || Amount < 0)
	{
		cout << "Error! Invalid number!" << endl;
		return;
	}
	setAmount(getAmount() - Amount);
}

void Book::increaseAmount(const int Amount)
{
	if (Amount < 0)
	{
		cout << "Error! Invalid number!" << endl;
		return;
	}
	setAmount(getAmount() + Amount);
}

void Book::rateTheBook(const double Rating)
{
	if (Rating < 0 || Rating > 10)
	{
		cout << "Error! Invalid number!" << endl;
		return;
	}
	NumberOfRatings++;
	setRating(((this->NumberOfRatings - 1)*this->Rating + Rating) / this->NumberOfRatings);
}

void Book::increasePrice(const double Price)
{
	if (Price < 0)
	{
		cout << "Error! Invalid number!" << endl;
		return;
	}
	setPrice(this->Price + Price);
}

void Book::decreasePrice(const double Price)
{
	if (Price < 0 || Price > this->Price)
	{
		cout << "Error! Invalid number!" << endl;
		return;
	}
	setPrice(this->Price - Price);
}

Book::~Book()
{
	delete[] Title;
	delete[] Author;
	delete[] Genre;
	Title = nullptr;
	Author = nullptr;
	Genre = nullptr;
}
