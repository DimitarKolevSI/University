#include "Product.h"

long long int IDCounter = 100000;
void Product::setID()
{
	this->ID = IDCounter;
	IDCounter++;
}

void Product::setYear(const int Year)
{
	this->Year = Year;
}

void Product::setPrice(const double Price)
{
	this->Price = Price;
}

void Product::setAmount(const int Amount)
{
	this->Amount = Amount;
}

void Product::setRating(const double Rating)
{
	this->Rating = Rating;
}

void Product::setNumberOfRatings(const int NumberOfRatings)
{
	this->NumberOfRatings = NumberOfRatings;
}

Product::Product()
{
	setYear(0);
	setPrice(0);
	setAmount(0);
	setRating(0);
	setNumberOfRatings(0);
	this->ID = 0;
}

Product::Product(const int Year, const double Price, const int Amount)
{
	setID();
	setYear(Year);
	setPrice(Price);
	setAmount(Amount);
	setRating(0);
	setNumberOfRatings(0);
}

Product::Product(const int Year, const double Price, const int Amount, const double Rating, const int NumberOfRatings)
{
	setID();
	setYear(Year);
	setPrice(Price);
	setAmount(Amount);
	setRating(Rating);
	setNumberOfRatings(NumberOfRatings);
}

const bool Product::operator==(const Product & other)
{
	return other.ID == ID;
}

const long long int Product::getID() const
{
	return this->ID;
}

const int Product::getYear() const
{
	return this->Year;
}

const double Product::getPrice() const
{
	return this->Price;
}

const int Product::getAmount() const
{
	return this->Amount;
}

const double Product::getRating() const
{
	return this->Rating;
}

const int Product::getNumberOfRatings() const
{
	return this->NumberOfRatings;
}

void Product::decreaseAmount(const int Amount)
{
	if (Amount > this->Amount || Amount < 0)
	{
		cout << "Error! Invalid number!" << endl;
		return;
	}
	setAmount(getAmount() - Amount);
}

void Product::increaseAmount(const int Amount)
{
	if (Amount < 0)
	{
		cout << "Error! Invalid number!" << endl;
		return;
	}
	setAmount(getAmount() + Amount);
}

void Product::rateTheProduct(const double Rating)
{
	if (Rating < 0 || Rating > 10)
	{
		cout << "Error! Invalid number!" << endl;
		return;
	}
	NumberOfRatings++;
	setRating(((this->NumberOfRatings - 1)*this->Rating + Rating) / this->NumberOfRatings);
}

void Product::increasePrice(const double Price)
{
	if (Price < 0)
	{
		cout << "Error! Invalid number!" << endl;
		return;
	}
	setPrice(this->Price + Price);
}

void Product::decreasePrice(const double Price)
{
	if (Price < 0 || Price > this->Price)
	{
		cout << "Error! Invalid number!" << endl;
		return;
	}
	setPrice(this->Price - Price);
}

ostream & operator<<(ostream & out, const Product & product)
{
	out << "ID: " << product.ID << endl;
	out << "Year: " << product.Year << endl;
	out << "Price: " << product.Price << endl;
	out << "Amount: " << product.Amount << endl;
	out << "Rating: " << product.Rating << "/10 from " << product.NumberOfRatings << " ratings.\n";
	return out;
}
