#pragma once
class SmartPhone
{
private:
	char* Brand = nullptr;
	char* Model = nullptr;
	double Price;
	int Amount;
	int Year;
	double Rating;
	int NumberOfRatings;
	void setBrand(const char* Brand);
	void setModel(const char* Model);
	void setPrice(const double Price);
	void setAmount(const int Amount);
	void setYear(const int Year);
	void setRating(const double Rating);
	void setNumberOfRatings(const int NumberOfRatings);
public:

	SmartPhone();
	SmartPhone(const char* Brand, const char* Model, const double Price, const int Amount, const int Year);
	SmartPhone(const char* Brand, const char* Model, const double Price, const int Amount, const int Year, const double Rating, const int NumberOfRatings);
	SmartPhone(const SmartPhone& Copy);
	SmartPhone& operator= (const SmartPhone& Copy);

	const char* getBrand() const;
	const char* getModel() const;
	const double getPrice() const;
	const int getAmount() const;
	const int getYear() const;
	const double getRating() const;
	const int getNumberOfRatings() const;

	const void print() const;
	void decreaseAmount(const int Amount);
	void increaseAmount(const int Amount);
	void rateTheSmartPhone(const double Rating);
	void increasePrice(const double Price);
	void decreasePrice(const double Price);

	~SmartPhone();
};