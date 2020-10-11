#pragma once
class Laptop
{
private:
	char* Brand = nullptr;
	char* Model = nullptr;
	char* Category = nullptr;
	double Price;
	int Amount;
	int Year;
	double Rating;
	int NumberOfRatings;
	void setBrand(const char* Brand);
	void setModel(const char* Model);
	void setCategory(const char* Category);
	void setPrice(const double Price);
	void setAmount(const int Amount);
	void setYear(const int Year);
	void setRating(const double Rating);
	void setNumberOfRatings(const int NumberOfRatings);
public:

	Laptop();
	Laptop(const char* Brand, const char* Model, const char* Category, const double Price, const int Amount, const int Year);
	Laptop(const char* Brand, const char* Model, const char* Category, const double Price, const int Amount, const int Year, const double Rating, const int NumberOfRatings);
	Laptop(const Laptop& Copy);
	Laptop& operator= (const Laptop& Copy);

	const char* getBrand() const;
	const char* getModel() const;
	const char* getCategory() const;
	const double getPrice() const;
	const int getAmount() const;
	const int getYear() const;
	const double getRating() const;
	const int getNumberOfRatings() const;

	const void print() const;
	void decreaseAmount(const int Amount);
	void increaseAmount(const int Amount);
	void rateTheLaptop(const double Rating);
	void increasePrice(const double Price);
	void decreasePrice(const double Price);

	~Laptop();
};