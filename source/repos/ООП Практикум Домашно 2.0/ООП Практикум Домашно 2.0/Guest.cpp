#include "Guest.h"
int IDCounter = 1000;
void Guest::setID()
{
	this->ID = IDCounter;
	IDCounter++;
}

Guest::Guest()
{
	setID();
}

const int Guest::getID() const
{
	return this->ID;
}

void Guest::addProductToShoppingCart(const Product & newProduct, const int amount)
{
	this->shoppingCart.addProduct(newProduct, amount);
}

void Guest::removeProductFromShoppingCart(const Product & product)
{
	this->shoppingCart.removeProduct(product);
}

void Guest::removeProductFromShoppingCartWithIndex(const int index)
{
	if (index < 0 || index >= this->shoppingCart.getSize()) return;
	this->shoppingCart.removeProductWithIndex(index);
}

double Guest::pay() 
{
	return shoppingCart.emptyTheCart();
}
