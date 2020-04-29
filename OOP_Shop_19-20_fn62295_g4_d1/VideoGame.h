#pragma once
class VideoGame
{
private:
	char* Name = nullptr;
	char* Creator = nullptr;
	char* Platform = nullptr;
	int Year;
	double Price;
	int Amount;
	double Rating;
	int NumberOfRatings;

	void setName(const char* Name);
	void setCreator(const char* Creator);
	void setPlatform(const char* Platform);
	void setYear(const int Year);
	void setPrice(const double Price);
	void setAmount(const int Amount);
	void setRating(const double Rating);
	void setNumberOfRatings(const int NumberOfRatings);

public:
	VideoGame();
	VideoGame(const char* Name, const char* Creator, const char* Platform, const int Year, const double Price, const int Amount);
	VideoGame(const char* Name, const char* Creator, const char* Platform, const int Year, const double Price, const int Amount, const double Rating, const int NumberOfRatings);
	VideoGame(const VideoGame& Copy);
	VideoGame& operator=(const VideoGame& Copy);

	const char* getName() const;
	const char* getCreator() const;
	const char* getPlatform() const;
	const int getYear() const;
	const double getPrice() const;
	const int getAmount() const;
	const double getRating() const;
	const int getNumberOfRatings() const;
	
	const void print() const;
	void decreaseAmount(const int Amount);
	void increaseAmount(const int Amount);
	void rateTheGame(const double Rating);
	void increasePrice(const double Price);
	void decreasePrice(const double Price);

	~VideoGame();
};