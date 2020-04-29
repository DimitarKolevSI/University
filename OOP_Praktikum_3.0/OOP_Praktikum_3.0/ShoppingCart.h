#pragma once
#include "Vector.h"
#include "Product.h"
#include "Book.h"
#include "Smartphone.h"
#include "VideoGame.h"
#include "Laptop.h"
class ShoppingCart
{
private:
	Vector<Product> Products;
	Vector<Book> Books;
	Vector<Laptop> Laptops;
	Vector<SmartPhone> SmartPhones;
	Vector<VideoGame> VideoGames;
	const double calculate() const;
	template <typename T>
	const double calculateHelper(const Vector<T>& list ) const;
	template <typename T>
	void Print(const Vector<T>& list) const;

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

template<typename T>
inline const double ShoppingCart::calculateHelper(const Vector<T>& list) const
{
	double bill = 0;
	for (int i = 0; i < list.getSize(); i++) {
		bill += list.getAt(i).getPrice();
	}
	return bill;
}

template<typename T>
inline void ShoppingCart::Print(const Vector<T>& list) const
{
	for (int i = 0; i < list.getSize(); i++) {
		cout << list.getAt(i);
	}
}
