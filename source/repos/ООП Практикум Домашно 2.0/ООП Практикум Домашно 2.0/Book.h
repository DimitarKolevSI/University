#pragma once
class Book
{
private:
	char* Title = nullptr;
	char* Author = nullptr;
	char* Genre = nullptr;
	int Pages;
	double Price;
	int Amount;
	int Year;
	double Rating;
	int NumberOfRatings;
	void setTitle(const char* Brand);
	void setAuthor(const char* Model);
	void setGenre(const char* Category);
	void setPages(const int Pages);
	void setPrice(const double Price);
	void setAmount(const int Amount);
	void setYear(const int Year);
	void setRating(const double Rating);
	void setNumberOfRatings(const int NumberOfRatings);
public:

	Book();
	Book(const char* Title, const char* Author, const char* Genre, const int Pages, const double Price, const int Amount, const int Year);
	Book(const char* Title, const char* Author, const char* Genre, const int Pages, const double Price, const int Amount, const int Year, const double Rating, const int NumberOfRatings);
	Book(const Book& Copy);
	Book& operator= (const Book& Copy);

	const char* getTitle() const;
	const char* getAuthor() const;
	const char* getGenre() const;
	const int getPages() const;
	const double getPrice() const;
	const int getAmount() const;
	const int getYear() const;
	const double getRating() const;
	const int getNumberOfRatings() const;

	const void print() const;
	void decreaseAmount(const int Amount);
	void increaseAmount(const int Amount);
	void rateTheBook(const double Rating);
	void increasePrice(const double Price);
	void decreasePrice(const double Price);

	~Book();
};