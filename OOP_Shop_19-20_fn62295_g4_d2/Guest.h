#pragma once
#include "ShoppingCart.h"
class Guest
{
private:
	int ID;
	ShoppingCart shoppingCart;
	void setID();
public:
	Guest();

	//Methods to be added:
	//Copy constructor
	//operator=
	//destructor
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
	
	const int getID() const;
};