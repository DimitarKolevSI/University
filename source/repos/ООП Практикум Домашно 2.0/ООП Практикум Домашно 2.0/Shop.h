#pragma once
#include "Storage.h"
#include "Registered.h"
#include "Guest.h"
#include "ListOfBooks.h"
#include "ListOfLaptops.h"
#include "ListOfSmartphones.h"
#include "ListOfVideoGames.h"

class Shop
{
private:
	ListOfBooks Books;
	ListOfLaptops Laptops;
	ListOfSmartPhones SmartPhones;
	ListOfVideoGames VideoGames;
	Storage Products;
	Registered* Users;
	Guest* Guests;
	int AmountOfUsers;
	int MaxUsers;
	int AmountOfGuests;
	int MaxGuests;

	void setAmountOfUsers(const int AmountOfUsers);
	void setMaxUsers(const int MaxUsers);
	void setAmountOfGuests(const int AmountOfGuests);
	void setMaxGuests(const int MaxGuests);
	void resizeForUsers();
	void resizeForGuests();
public:
	Shop();
	Shop(const int MaxUsers);
	Shop(const int MaxUsers, const int MaxGuests);
	Shop(const Shop& copy);
	const Shop& operator=(const Shop& copy);

	const int getAmountOfUsers() const;
	const int getMaxUsers() const;
	const int getAmountOfGuests() const;
	const int getMaxGuests() const;
	const Registered getUserAt(int index);
	const Guest getGuestAt(int index);

	void addGuest(const Guest& newGuest);
	void addUser(const Registered& newUser);
	void removeUser(const Registered& user);
	void removeGuest(const Guest& guest);
	void RegisterAGuest(const Guest& guest, const char* Username, const char* Password, const char* Email);
	
	void addProduct(const Product& newProduct);
	void removeProduct(const Product& product);
	void removeProductWithIndex(const int index);
	void printAllProducts() const;

	void addLaptop(const Laptop& newLaptop);
	void removeLaptop(const Laptop& Laptop);
	void printAllLaptops() const;
	void removeLaptopWithIndex(const int index);
	
	void addSmartPhone(const SmartPhone& newSmartPhone);
	void removeSmartPhone(const SmartPhone& SmartPhone);
	void removeSmartPhoneWithIndex(const int index);
	void printAllSmartPhones() const;
	
	void addBook(const Book& newBook);
	void removeBook(const Book& Book);
	void removeBookWithIndex(const int index);
	void printAllBooks() const;
	
	void addVideoGame(const VideoGame& newVideoGame);
	void removeVideoGame(const VideoGame& VideoGame);
	void removeVideoGameWithIndex(const int index);
	void printAllVideoGames() const;

	~Shop();
};