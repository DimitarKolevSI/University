#pragma once
#include"Product.h"
#include"Storage.h"
#include"ListOfBooks.h"
#include"ListOfLaptops.h"
#include"ListOfSmartphones.h"
#include"ListOfVideoGames.h"
class ShoppingCart
{
private:
	Storage Products;
	ListOfBooks Books;
	ListOfLaptops Laptops;
	ListOfSmartPhones SmartPhones;
	ListOfVideoGames VideoGames;

public:
	ShoppingCart();
	ShoppingCart(const ShoppingCart& copy);//copy constructor
	const ShoppingCart& operator= (const ShoppingCart& copy);  //operator=

	void addProduct(const Product& newProduct);//add product to the cart
	void removeProduct(const Product& product);
	void removeProductWithIndex(const int);

	void addBook(const Book& newBook);//add Book to the cart
	void removeBook(const Book& Book);
	void removeBookWithIndex(const int);

	void addLaptop(const Laptop& newLaptop);//add Laptop to the cart
	void removeLaptop(const Laptop& Laptop);
	void removeLaptopWithIndex(const int);

	void addSmartPhone(const SmartPhone& newSmartPhone);//add SmartPhone to the cart
	void removeSmartPhone(const SmartPhone& SmartPhone);
	void removeSmartPhoneWithIndex(const int);

	void addVideoGame(const VideoGame& newVideoGame);//add VideoGame to the cart
	void removeVideoGame(const VideoGame& VideoGame);
	void removeVideoGameWithIndex(const int);

	double emptyTheCart();//empty
	void printTheCart() const;
};