#pragma once
class ShoppingCart
{
private:
	int Size;
	int MaxSize;
	void setSize(const int Size);
	void setMaxSize(const int maxSize);
	//Variables to be added:
	//list of products
	//list of the amount of every product
public:
	ShoppingCart();
	ShoppingCart(const int maxSize);

	//Methods to be added:
	//copy constructor
	//operator=
	//destructor
	//add product to the cart
	//empty
	//setters and getters for the new variables

	const int getSize() const;
	const int getMaxSize() const;
};