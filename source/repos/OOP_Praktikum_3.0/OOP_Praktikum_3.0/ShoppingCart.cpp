#include "ShoppingCart.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

const double ShoppingCart::calculate() const
{
	double bill = calculateHelper(Products) + calculateHelper(Books) + calculateHelper(SmartPhones) +
		calculateHelper(Laptops) + calculateHelper(VideoGames);
	return bill;
}

ShoppingCart::ShoppingCart() :Products(), Books(), Laptops(), SmartPhones(), VideoGames()
{

}

ShoppingCart::ShoppingCart(const ShoppingCart & copy) : Products(copy.Products), Books(copy.Books), Laptops(copy.Laptops), 
														SmartPhones(copy.SmartPhones), VideoGames(copy.VideoGames)
{

}

const ShoppingCart & ShoppingCart::operator=(const ShoppingCart & copy)
{
	if (this != &copy) {
		this->Products = copy.Products;
	}
	return *this;
}

void ShoppingCart::addProduct(const Product & newProduct)
{
	Products.add(newProduct);
}

void ShoppingCart::removeProduct(const Product & product)
{
	Products.remove(product);
}

void ShoppingCart::removeProductWithIndex(const int index)
{
	Products.removeWithIndex(index);
}

void ShoppingCart::addBook(const Book & newBook)
{
	Books.add(newBook);
}

void ShoppingCart::removeBook(const Book & Book)
{
	Books.remove(Book);
}

void ShoppingCart::removeBookWithIndex(const int index)
{
	Books.removeWithIndex(index);
}

void ShoppingCart::addLaptop(const Laptop & newLaptop)
{
	Laptops.add(newLaptop);
}

void ShoppingCart::removeLaptop(const Laptop & Laptop)
{
	Laptops.remove(Laptop);
}

void ShoppingCart::removeLaptopWithIndex(const int index)
{
	Laptops.removeWithIndex(index);
}

void ShoppingCart::addSmartPhone(const SmartPhone & newSmartPhone)
{
	SmartPhones.add(newSmartPhone);
}

void ShoppingCart::removeSmartPhone(const SmartPhone & SmartPhone)
{
	SmartPhones.remove(SmartPhone);
}

void ShoppingCart::removeSmartPhoneWithIndex(const int index)
{
	SmartPhones.removeWithIndex(index);
}

void ShoppingCart::addVideoGame(const VideoGame & newVideoGame)
{
	VideoGames.add(newVideoGame);
}

void ShoppingCart::removeVideoGame(const VideoGame & VideoGame)
{
	VideoGames.remove(VideoGame);
}

void ShoppingCart::removeVideoGameWithIndex(const int index)
{
	VideoGames.removeWithIndex(index);
}

double ShoppingCart::emptyTheCart() {
	double bill = calculate();
	Products.empty();
	Books.empty();
	Laptops.empty();
	SmartPhones.empty();
	VideoGames.empty();
	return bill;
}

void ShoppingCart::printTheCart() const
{
	Print(Products);
	Print(Books);
	Print(Laptops);
	Print(SmartPhones);
	Print(VideoGames);
}
