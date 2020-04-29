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

void Guest::addProductToShoppingCart(const Product & newProduct)
{
	this->shoppingCart.addProduct(newProduct);
}

void Guest::removeProductFromShoppingCart(const Product & product)
{
	this->shoppingCart.removeProduct(product);
}

void Guest::removeProductFromShoppingCartWithIndex(const int index)
{
	this->shoppingCart.removeProductWithIndex(index);
}

void Guest::addBookToShoppingCart(const Book & newBook)
{
	this->shoppingCart.addBook(newBook);
}

void Guest::removeBookFromShoppingCart(const Book & Book)
{
	this->shoppingCart.removeBook(Book);
}

void Guest::removeBookFromShoppingCartWithIndex(const int index)
{
	this->shoppingCart.removeBookWithIndex(index);
}

void Guest::addLaptopToShoppingCart(const Laptop & newLaptop)
{
	this->shoppingCart.addLaptop(newLaptop);
}

void Guest::removeLaptopFromShoppingCart(const Laptop & Laptop)
{
	this->shoppingCart.removeLaptop(Laptop);
}

void Guest::removeLaptopFromShoppingCartWithIndex(const int index)
{
	this->shoppingCart.removeLaptopWithIndex(index);
}

void Guest::addSmartPhoneToShoppingCart(const SmartPhone & newSmartPhone)
{
	this->shoppingCart.addSmartPhone(newSmartPhone);
}

void Guest::removeSmartPhoneFromShoppingCart(const SmartPhone & SmartPhone)
{
	this->shoppingCart.removeSmartPhone(SmartPhone);
}

void Guest::removeSmartPhoneFromShoppingCartWithIndex(const int index)
{
	this->shoppingCart.removeSmartPhoneWithIndex(index);
}

void Guest::addVideoGameToShoppingCart(const VideoGame & newVideoGame)
{
	this->shoppingCart.addVideoGame(newVideoGame);
}

void Guest::removeVideoGameFromShoppingCart(const VideoGame & VideoGame)
{
	this->shoppingCart.removeVideoGame(VideoGame);
}

void Guest::removeVideoGameFromShoppingCartWithIndex(const int index)
{
	this->shoppingCart.removeVideoGameWithIndex(index);
}

double Guest::pay() 
{
	return shoppingCart.emptyTheCart();
}
