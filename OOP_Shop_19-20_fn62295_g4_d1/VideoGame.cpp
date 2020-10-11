#include "VideoGame.h"
#include <iostream>
#include <cstring>

using namespace std;

void VideoGame::setName(const char * Name)
{
	if (Name != nullptr) delete[] this->Name;
	this->Name = new char[strlen(Name) + 1];
	strcpy_s(this->Name, strlen(Name) + 1, Name);
}

void VideoGame::setCreator(const char * Creator)
{
	if (Creator != nullptr) delete[] this->Creator;
	this->Creator = new char[strlen(Creator) + 1];
	strcpy_s(this->Creator, strlen(Creator) + 1, Creator);
}

void VideoGame::setPlatform(const char * Platform)
{
	if (Platform != nullptr) delete[] this->Platform;
	this->Platform = new char[strlen(Platform) + 1];
	strcpy_s(this->Platform, strlen(Platform) + 1, Platform);
}

void VideoGame::setYear(const int Year)
{
	this->Year = Year;
}

void VideoGame::setPrice(const double Price)
{
	this->Price = Price;
}

void VideoGame::setAmount(const int Amount)
{
	this->Amount = Amount;
}

void VideoGame::setRating(const double Rating)
{
	this->Rating = Rating;
}

void VideoGame::setNumberOfRatings(const int NumberOfRatings)
{
	this->NumberOfRatings = NumberOfRatings;
}

VideoGame::VideoGame()
{
	setName("\0");
	setCreator("\0");
	setPlatform("\0");
	setYear(0);
	setPrice(0);
	setAmount(0);
	setRating(0);
	setNumberOfRatings(0);
}

VideoGame::VideoGame(const char * Name, const char * Creator, const char * Platform, const int Year, const double Price, const int Amount)
{
	setName(Name);
	setCreator(Creator);
	setPlatform(Platform);
	setYear(Year);
	setPrice(Price);
	setAmount(Amount);
	setRating(0);
	setNumberOfRatings(0);
}

VideoGame::VideoGame(const char * Name, const char * Creator, const char * Platform, const int Year, const double Price, const int Amount, const double Rating, const int NumberOfRatings)
{
	setName(Name);
	setCreator(Creator);
	setPlatform(Platform);
	setYear(Year);
	setPrice(Price);
	setAmount(Amount);
	setRating(Rating);
	setNumberOfRatings(NumberOfRatings);
}

VideoGame::VideoGame(const VideoGame & Copy)
{
	setName(Copy.Name);
	setCreator(Copy.Creator);
	setPlatform(Copy.Platform);
	setYear(Copy.Year);
	setPrice(Copy.Price);
	setAmount(Copy.Amount);
	setRating(Copy.Rating);
	setNumberOfRatings(Copy.NumberOfRatings);
}

VideoGame & VideoGame::operator=(const VideoGame & Copy)
{
	if (this != &Copy)
	{
		setName(Copy.Name);
		setCreator(Copy.Creator);
		setPlatform(Copy.Platform);
		setYear(Copy.Year);
		setPrice(Copy.Price);
		setAmount(Copy.Amount);
		setRating(Copy.Rating);
		setNumberOfRatings(Copy.NumberOfRatings);
	}
	return *this;
}

const char * VideoGame::getName() const
{
	return this->Name;
}

const char * VideoGame::getCreator() const
{
	return this->Creator;
}

const char * VideoGame::getPlatform() const
{
	return this->Platform;
}

const int VideoGame::getYear() const
{
	return this->Year;
}

const double VideoGame::getPrice() const
{
	return this->Price;
}

const int VideoGame::getAmount() const
{
	return this->Amount;
}

const double VideoGame::getRating() const
{
	return this->Rating;
}

const int VideoGame::getNumberOfRatings() const
{
	return this->NumberOfRatings;
}

const void VideoGame::print() const
{
	cout << "Name: " << this->Name << endl;
	cout << "Creator: " << this->Creator << endl;
	cout << "Platform: " << this->Platform << endl;
	cout << "Year: " << this->Year << endl;
	cout << "Price: " << this->Price << endl;
	cout << "Amount: " << this->Amount << endl;
	cout << "Rating: " << this->Rating << "/10 from " << this->NumberOfRatings << " ratings.\n";
}

void VideoGame::decreaseAmount(const int Amount)
{
	if (Amount > this->Amount || Amount < 0)
	{
		cout << "Error! Invalid number!" << endl;
		return;
	}
	setAmount(getAmount() - Amount);
}

void VideoGame::increaseAmount(const int Amount)
{
	if (Amount < 0)
	{
		cout << "Error! Invalid number!" << endl;
		return;
	}
	setAmount(getAmount() + Amount);
}

void VideoGame::rateTheGame(const double Rating)
{
	if (Rating < 0 || Rating > 10)
	{
		cout << "Error! Invalid number!" << endl;
		return;
	} 
	NumberOfRatings++;
	setRating(((this->NumberOfRatings - 1)*this->Rating + Rating) / this->NumberOfRatings);
}

void VideoGame::increasePrice(const double Price)
{
	if (Price < 0)
	{
		cout << "Error! Invalid number!" << endl;
		return;
	}
	setPrice(this->Price + Price);
}

void VideoGame::decreasePrice(const double Price)
{
	if (Price < 0 || Price > this->Price)
	{
		cout << "Error! Invalid number!" << endl;
		return;
	}
	setPrice(this->Price - Price);
}

VideoGame::~VideoGame()
{
	delete[] this->Name;
	delete[] this->Creator;
	delete[] this->Platform;
	this->Name = nullptr;
	this->Creator = nullptr;
	this->Platform = nullptr;
}