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
	//Add to shopping cart
	void addProductToShoppingCart(const Product& newProduct, const int amount);
	//Remove from shopping cart
	void removeProductFromShoppingCart(const Product& product);
	void removeProductFromShoppingCartWithIndex(const int index);
	//Pay
	double pay();
	
	const int getID() const;
};