#pragma once
#include"Product.h"
class ShoppingCart
{
private:
	int Size;
	int MaxSize;
	void setSize(const int Size);
	void setMaxSize(const int maxSize);
	//Variables to be added:
	Product* listOfProducts = nullptr;//list of products
	int* amountOfProduct = nullptr;//list of the amount of every product
	void resize();
public:
	ShoppingCart();
	ShoppingCart(const int maxSize);

	//Methods to be added:
	ShoppingCart(const ShoppingCart& copy);//copy constructor
	const ShoppingCart& operator= (const ShoppingCart& copy);  //operator=
	//destructor
	void addProduct(const Product& newProduct, int amount);//add product to the cart
	void removeProduct(const Product& product);
	void removeProductWithIndex(const int);
	double emptyTheCart();//empty
	void printTheCart() const;

	//setters and getters for the new variables
	const int getSize() const;
	const int getMaxSize() const;

	~ShoppingCart();
};