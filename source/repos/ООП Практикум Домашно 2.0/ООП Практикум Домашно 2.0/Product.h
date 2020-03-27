#pragma once
class Product
{
private:
	int ID;
	int Year;
	double Price;
	int Amount;
	double Rating;
	int NumberOfRatings;
	void setID();
	void setYear(const int Year);
	void setPrice(const double Price);
	void setAmount(const int Amount);
	void setRating(const double Rating);
	void setNumberOfRatings(const int NumberOfRatings);
public:
	Product();
	Product(const int Year, const double Price, const int Amount);
	Product(const int Year, const double Price, const int Amount, const double Rating, const int NumberOfRatings);

	const int getYear() const;
	const double getPrice() const;
	const int getAmount() const;
	const double getRating() const;
	const int getNumberOfRatings() const;
	const long long int getID() const;

	const void print() const;
	void decreaseAmount(const int Amount);
	void increaseAmount(const int Amount);
	void rateTheProduct(const double Rating);
	void increasePrice(const double Price);
	void decreasePrice(const double Price);

	
};