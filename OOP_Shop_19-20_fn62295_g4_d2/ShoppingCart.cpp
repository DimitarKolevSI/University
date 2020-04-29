#include "ShoppingCart.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

ShoppingCart::ShoppingCart() :Products(), Books(), Laptops(), SmartPhones(), VideoGames()
{
	
}

ShoppingCart::ShoppingCart(const ShoppingCart & copy) : Products(copy.Products), Books(copy.Books), Laptops(copy.Laptops), SmartPhones(copy.SmartPhones), VideoGames(copy.VideoGames)
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
	Products.addProduct(newProduct);
}

void ShoppingCart::removeProduct(const Product & product)
{
	Products.removeProduct(product);
}

void ShoppingCart::removeProductWithIndex(const int index)
{
	Products.removeProductWithIndex(index);
}

void ShoppingCart::addBook(const Book & newBook)
{
	Books.addBook(newBook);
}

void ShoppingCart::removeBook(const Book & Book)
{
	Books.removeBook(Book);
}

void ShoppingCart::removeBookWithIndex(const int index)
{
	Books.removeBookWithIndex(index);
}

void ShoppingCart::addLaptop(const Laptop & newLaptop)
{
	Laptops.addLaptop(newLaptop);
}

void ShoppingCart::removeLaptop(const Laptop & Laptop)
{
	Laptops.removeLaptop(Laptop);
}

void ShoppingCart::removeLaptopWithIndex(const int index)
{
	Laptops.removeLaptopWithIndex(index);
}

void ShoppingCart::addSmartPhone(const SmartPhone & newSmartPhone)
{
	SmartPhones.addSmartPhone(newSmartPhone);
}

void ShoppingCart::removeSmartPhone(const SmartPhone & SmartPhone)
{
	SmartPhones.removeSmartPhone(SmartPhone);
}

void ShoppingCart::removeSmartPhoneWithIndex(const int index)
{
	SmartPhones.removeSmartPhoneWithIndex(index);
}

void ShoppingCart::addVideoGame(const VideoGame & newVideoGame)
{
	VideoGames.addVideoGame(newVideoGame);
}

void ShoppingCart::removeVideoGame(const VideoGame & VideoGame)
{
	VideoGames.removeVideoGame(VideoGame);
}

void ShoppingCart::removeVideoGameWithIndex(const int index)
{
	VideoGames.removeVideoGameWithIndex(index);
}

double ShoppingCart::emptyTheCart(){
	double bill = Products.calculate() + Books.calculate() + Laptops.calculate() + SmartPhones.calculate() + VideoGames.calculate();
	Products.~Storage();
	Books.~ListOfBooks();
	Laptops.~ListOfLaptops();
	SmartPhones.~ListOfSmartPhones();
	VideoGames.~ListOfVideoGames();
	return bill;
}

void ShoppingCart::printTheCart() const
{
	Products.printAllProducts();
}
