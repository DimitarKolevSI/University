#include "Laptop.h"
#include <cstring>
#include <iostream>

using namespace std;

void Laptop::setBrand(const char * Brand)
{
	if (this->Brand != nullptr) delete[] this->Brand;
	this->Brand = new char[strlen(Brand) + 1];
	strcpy_s(this->Brand, strlen(Brand) + 1, Brand);
}

void Laptop::setModel(const char * Model)
{
	if (this->Model != nullptr) delete[] this->Model;
	this->Model = new char[strlen(Model) + 1];
	strcpy_s(this->Model, strlen(Model) + 1, Model);
}

void Laptop::setCategory(const char * Category)
{
	if (this->Category != nullptr) delete[] this->Category;
	this->Category = new char[strlen(Category) + 1];
	strcpy_s(this->Category, strlen(Category) + 1, Category);
}

void Laptop::setPrice(const double Price)
{
	this->Price = Price;
}

void Laptop::setAmount(const int Amount)
{
	this->Amount = Amount;
}

void Laptop::setYear(const int Year)
{
	this->Year = Year;
}

void Laptop::setRating(const double Rating)
{
	this->Rating = Rating;
}

void Laptop::setNumberOfRatings(const int NumberOfRatings)
{
	this->NumberOfRatings = NumberOfRatings;
}

Laptop::Laptop()
{
	setModel("\0");
	setBrand("\0");
	setCategory("\0");
	setPrice(0);
	setAmount(0);
	setYear(0);
	setRating(0);
	setNumberOfRatings(0);
}

Laptop::Laptop(const char *Brand, const char *Model, const char *Category, const double Price, const int Amount, int Year)
{
	setBrand(Brand);
	setModel(Model);
	setCategory(Category);
	setPrice(Price);
	setAmount(Amount);
	setYear(Year);
	setRating(0);
	setNumberOfRatings(0);
}

Laptop::Laptop(const char * Brand, const char * Model, const char * Category, const double Price, const int Amount, const int Year, const double Rating, const int NumberOfRatings)
{
	setBrand(Brand);
	setModel(Model);
	setCategory(Category);
	setPrice(Price);
	setAmount(Amount);
	setYear(Year);
	setRating(Rating);
	setNumberOfRatings(NumberOfRatings);
}

Laptop::Laptop(const Laptop & CopyObject)
{
	setBrand(CopyObject.getBrand());
	setModel(CopyObject.getModel());
	setCategory(CopyObject.getCategory());
	setPrice(CopyObject.getPrice());
	setAmount(CopyObject.getAmount());
	setYear(CopyObject.getYear());
	setRating(CopyObject.getRating());
	setNumberOfRatings(CopyObject.getNumberOfRatings());
}

Laptop & Laptop::operator=(const Laptop & CopyObject)
{
	if (this != &CopyObject)
	{
		setBrand(CopyObject.getBrand());
		setModel(CopyObject.getModel());
		setCategory(CopyObject.getCategory());
		setPrice(CopyObject.getPrice());
		setAmount(CopyObject.getAmount());
		setYear(CopyObject.getYear());
		setRating(CopyObject.getRating());
		setNumberOfRatings(CopyObject.getNumberOfRatings());
	}
	return *this;
}

const char * Laptop::getBrand() const
{
	return this->Brand;
}

const char * Laptop::getModel() const
{
	return this->Model;
}

const char * Laptop::getCategory() const
{
	return this->Category;
}

const double Laptop::getPrice() const
{
	return this->Price;
}

const int Laptop::getAmount() const
{
	return this->Amount;
}

const int Laptop::getYear() const
{
	return this->Year;
}

const double Laptop::getRating() const
{
	return this->Rating;
}

const int Laptop::getNumberOfRatings() const
{
	return this->NumberOfRatings;
}

const void Laptop::print() const
{
	cout << "Brand: " << this->Brand << endl;
	cout << "Model: " << this->Model << endl;
	cout << "Category: " << this->Category << endl;
	cout << "Year: " << this->Year << endl;
	cout << "Price: " << this->Price << endl;
	cout << "Amount: " << this->Amount << endl;
	cout << "Rating: " << this->Rating << "/10 from " << this->NumberOfRatings << " ratings.\n";
}

void Laptop::decreaseAmount(const int Amount)
{
	if (Amount > this->Amount || Amount < 0)
	{
		cout << "Error! Invalid number!" << endl;
		return;
	}
	setAmount(getAmount() - Amount);
}

void Laptop::increaseAmount(const int Amount)
{
	if (Amount < 0)
	{
		cout << "Error! Invalid number!" << endl;
		return;
	}
	setAmount(getAmount() + Amount);
}

void Laptop::rateTheLaptop(const double Rating)
{
	if (Rating < 0 || Rating > 10)
	{
		cout << "Error! Invalid number!" << endl;
		return;
	}
	NumberOfRatings++;
	setRating(((this->NumberOfRatings - 1)*this->Rating + Rating) / this->NumberOfRatings);
}

void Laptop::increasePrice(const double Price)
{
	if (Price < 0)
	{
		cout << "Error! Invalid number!" << endl;
		return;
	}
	setPrice(this->Price + Price);
}

void Laptop::decreasePrice(const double Price)
{
	if (Price < 0 || Price > this->Price)
	{
		cout << "Error! Invalid number!" << endl;
		return;
	}
	setPrice(this->Price - Price);
}

Laptop::~Laptop()
{
	delete[] Brand;
	delete[] Model;
	delete[] Category;
	Brand = nullptr;
	Model = nullptr;
	Category = nullptr;
}
