#include "SmartPhone.h"
#include <cstring>
#include <iostream>

using namespace std;

void SmartPhone::setBrand(const char * Brand)
{
	if (this->Brand != nullptr) delete[] this->Brand;
	this->Brand = new char[strlen(Brand) + 1];
	strcpy_s(this->Brand, strlen(Brand) + 1, Brand);
}

void SmartPhone::setModel(const char * Model)
{
	if (this->Model != nullptr) delete[] this->Model;
	this->Model = new char[strlen(Model) + 1];
	strcpy_s(this->Model, strlen(Model) + 1, Model);
}


void SmartPhone::setPrice(const double Price)
{
	this->Price = Price;
}

void SmartPhone::setAmount(const int Amount)
{
	this->Amount = Amount;
}

void SmartPhone::setYear(const int Year)
{
	this->Year = Year;
}

void SmartPhone::setRating(const double Rating)
{
	this->Rating = Rating;
}

void SmartPhone::setNumberOfRatings(const int NumberOfRatings)
{
	this->NumberOfRatings = NumberOfRatings;
}

SmartPhone::SmartPhone()
{
	setModel("\0");
	setBrand("\0");
	setPrice(0);
	setAmount(0);
	setYear(0);
	setRating(0);
	setNumberOfRatings(0);
}

SmartPhone::SmartPhone(const char *Brand, const char *Model, const double Price, const int Amount, int Year)
{
	setBrand(Brand);
	setModel(Model);
	setPrice(Price);
	setAmount(Amount);
	setYear(Year);
	setRating(0);
	setNumberOfRatings(0);
}

SmartPhone::SmartPhone(const char * Brand, const char * Category, const double Price, const int Amount, const int Year, const double Rating, const int NumberOfRatings)
{
	setBrand(Brand);
	setModel(Model);
	setPrice(Price);
	setAmount(Amount);
	setYear(Year);
	setRating(Rating);
	setNumberOfRatings(NumberOfRatings);
}

SmartPhone::SmartPhone(const SmartPhone & CopyObject)
{
	setBrand(CopyObject.getBrand());
	setModel(CopyObject.getModel());
	setPrice(CopyObject.getPrice());
	setAmount(CopyObject.getAmount());
	setYear(CopyObject.getYear());
	setRating(CopyObject.getRating());
	setNumberOfRatings(CopyObject.getNumberOfRatings());
}

SmartPhone & SmartPhone::operator=(const SmartPhone & CopyObject)
{
	if (this != &CopyObject)
	{
		setBrand(CopyObject.getBrand());
		setModel(CopyObject.getModel());
		setPrice(CopyObject.getPrice());
		setAmount(CopyObject.getAmount());
		setYear(CopyObject.getYear());
		setRating(CopyObject.getRating());
		setNumberOfRatings(CopyObject.getNumberOfRatings());
	}
	return *this;
}

const char * SmartPhone::getBrand() const
{
	return this->Brand;
}

const char * SmartPhone::getModel() const
{
	return this->Model;
}

const double SmartPhone::getPrice() const
{
	return this->Price;
}

const int SmartPhone::getAmount() const
{
	return this->Amount;
}

const int SmartPhone::getYear() const
{
	return this->Year;
}

const double SmartPhone::getRating() const
{
	return this->Rating;
}

const int SmartPhone::getNumberOfRatings() const
{
	return this->NumberOfRatings;
}

const void SmartPhone::print() const
{
	cout << "Brand: " << this->Brand << endl;
	cout << "Model: " << this->Model << endl;
	cout << "Year: " << this->Year << endl;
	cout << "Price: " << this->Price << endl;
	cout << "Amount: " << this->Amount << endl;
	cout << "Rating: " << this->Rating << "/10 from " << this->NumberOfRatings << " ratings.\n";
}

void SmartPhone::decreaseAmount(const int Amount)
{
	if (Amount > this->Amount || Amount < 0)
	{
		cout << "Error! Invalid number!" << endl;
		return;
	}
	setAmount(getAmount() - Amount);
}

void SmartPhone::increaseAmount(const int Amount)
{
	if (Amount < 0)
	{
		cout << "Error! Invalid number!" << endl;
		return;
	}
	setAmount(getAmount() + Amount);
}

void SmartPhone::rateTheSmartPhone(const double Rating)
{
	if (Rating < 0 || Rating > 10)
	{
		cout << "Error! Invalid number!" << endl;
		return;
	}
	NumberOfRatings++;
	setRating(((this->NumberOfRatings - 1)*this->Rating + Rating) / this->NumberOfRatings);
}

void SmartPhone::increasePrice(const double Price)
{
	if (Price < 0)
	{
		cout << "Error! Invalid number!" << endl;
		return;
	}
	setPrice(this->Price + Price);
}

void SmartPhone::decreasePrice(const double Price)
{
	if (Price < 0 || Price > this->Price)
	{
		cout << "Error! Invalid number!" << endl;
		return;
	}
	setPrice(this->Price - Price);
}

SmartPhone::~SmartPhone()
{
	delete[] Brand;
	delete[] Model;
	Brand = nullptr;
	Model = nullptr;
}
