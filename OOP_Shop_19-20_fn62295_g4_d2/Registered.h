#pragma once
#include "ShoppingCart.h"
class Registered
{
private:
	int ID;
	char* Username = nullptr;
	char* Password = nullptr;
	char* Email = nullptr;
	bool loggedIn;
	ShoppingCart shoppingCart;
	friend class Shop;
	//Things to be added:
	//Hstory of purcheses
	
	void setID();
	void setUsername(const char* Username);
	void setPassword(const char* Password);
	void setEmail(const char* Email);
	const char* getPassword() const;
	void switchLog();

public:

	Registered();
	Registered(const char* Username, const char* Password, const char* Email);
	Registered(const Registered& oldUser);
	Registered& operator=(const Registered& oldUser);

	const char* getUsername() const;
	const char* getEmail() const;
	const int getID() const;
	void changePassword();
	void logIn();
	void logOut();
	void addProductToShoppingCart(const Product& newProduct);
	void removeProductFromShoppingCart(const Product& product);
	void removeProductFromShoppingCartWithIndex(const int index);

	void addBookToShoppingCart(const Book& newBook);
	void removeBookFromShoppingCart(const Book& Book);
	void removeBookFromShoppingCartWithIndex(const int index);

	void addLaptopToShoppingCart(const Laptop& newLaptop);
	void removeLaptopFromShoppingCart(const Laptop& Laptop);
	void removeLaptopFromShoppingCartWithIndex(const int index);

	void addSmartPhoneToShoppingCart(const SmartPhone& newSmartPhone);
	void removeSmartPhoneFromShoppingCart(const SmartPhone& SmartPhone);
	void removeSmartPhoneFromShoppingCartWithIndex(const int index);

	void addVideoGameToShoppingCart(const VideoGame& newVideoGame);
	void removeVideoGameFromShoppingCart(const VideoGame& VideoGame);
	void removeVideoGameFromShoppingCartWithIndex(const int index);
	double pay();
	void print() const;

	~Registered();
};