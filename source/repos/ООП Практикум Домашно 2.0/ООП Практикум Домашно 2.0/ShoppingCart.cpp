#include "ShoppingCart.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void ShoppingCart::setSize(const int Size)
{
	this->Size = Size;
}

void ShoppingCart::setMaxSize(const int maxSize)
{
	this->MaxSize = maxSize;
}

void ShoppingCart::resize()
{
	cout << "Resize called" << endl;
	this->MaxSize *= 2;
	Product* temp = new Product[this->MaxSize];
	int* tempA = new int[this->MaxSize];
	for (int i = 0; i < this->Size; i++) {
		temp[i] = this->listOfProducts[i];
		tempA[i] = this->amountOfProduct[i];
	}
	delete[] listOfProducts;
	delete[] amountOfProduct;
	listOfProducts = temp;
	amountOfProduct = tempA;
}

ShoppingCart::ShoppingCart()
{
	setSize(0);
	setMaxSize(1);
	this->listOfProducts = new Product[this->MaxSize];
	this->amountOfProduct = new int[this->MaxSize];
}

ShoppingCart::ShoppingCart(const int maxSize)
{
	setSize(0);
	setMaxSize(maxSize);
	this->listOfProducts = new Product[this->MaxSize];
	this->amountOfProduct = new int[this->MaxSize];
}

ShoppingCart::ShoppingCart(const ShoppingCart & copy)
{
	setSize(copy.Size);
	setMaxSize(copy.MaxSize);
	this->listOfProducts = new Product[this->MaxSize];
	this->amountOfProduct = new int[this->MaxSize];
	for (int i = 0; i < this->Size; i++) {
		this->listOfProducts[i] = copy.listOfProducts[i];
		this->amountOfProduct[i] = copy.amountOfProduct[i];
	}
}

const ShoppingCart & ShoppingCart::operator=(const ShoppingCart & copy)
{
	if (this != &copy) {
		setSize(copy.Size);
		setMaxSize(copy.MaxSize);
		delete[] listOfProducts;
		delete[] amountOfProduct;
		listOfProducts = nullptr;
		amountOfProduct = nullptr;
		this->listOfProducts = new Product[this->MaxSize];
		this->amountOfProduct = new int[this->MaxSize];
		for (int i = 0; i < this->Size; i++) {
			this->listOfProducts[i] = copy.listOfProducts[i];
			this->amountOfProduct[i] = copy.amountOfProduct[i];
		}
	}
	return *this;
}

void ShoppingCart::addProduct(const Product & newProduct, int amount)
{
	if (amount == 0 || newProduct.getAmount() < amount) {
		cout << "Wrong input for amount! Can't add this product!" << endl;
		return;
	}
	if (this->Size == this->MaxSize) {
		resize();
	}

	listOfProducts[this->Size] = newProduct;
	amountOfProduct[this->Size] = amount;
	this->Size++;
}

void ShoppingCart::removeProduct(const Product & product)
{
	for (int i = 0; i < this->Size; i++) {
		if (product.getID() == listOfProducts[i].getID()) {
			removeProductWithIndex(i);
			return;
		}
	}
}

void ShoppingCart::removeProductWithIndex(const int index)
{
	if (index == this->Size) {
		this->Size--;
		return;
	}
	for (int i = index; i < this->Size - 1; i++) {
		listOfProducts[i] = listOfProducts[i + 1];
		amountOfProduct[i] = amountOfProduct[i + 1];
	}
	this->Size--;
}

double ShoppingCart::emptyTheCart(){
	double bill = 0;
	for (int i = 0; i < Size; i++) {
		bill += (listOfProducts[i].getPrice() * amountOfProduct[i]);
	}
	this->~ShoppingCart();
	this->Size = 0;
	this->MaxSize = 10;
	listOfProducts = new Product[MaxSize];
	amountOfProduct = new int[MaxSize];
	return bill;
}

void ShoppingCart::printTheCart() const
{
	if (this->Size == 0) {
		cout << "The cart is empty!" << endl;
		return;
	}
	for (int i = 0; i < this->Size; i++) {
		listOfProducts[i].print();
		cout << "Amount: " << this->amountOfProduct[i] << endl;
	}
	/*char action;
	for (int i = 0; i < this->Size; i++) {
		listOfProducts[i].print();
		cout << "Amount: " << this->amountOfProduct[i] << endl;
		cout << "Type P for previous product or N for Next: ";
		cin >> action;
		if (action == 'p' || action == 'P') i = i - 2 < 0 ? 0 : i - 2;
		else if (action != 'n' && action != 'N') break;
		system("CLS");
	}*/
}

const int ShoppingCart::getSize() const
{
	return this->Size;
}

const int ShoppingCart::getMaxSize() const
{
	return this->MaxSize;
}

ShoppingCart::~ShoppingCart()
{
	delete[] listOfProducts;
	delete[] amountOfProduct;
	listOfProducts = nullptr;
	amountOfProduct = nullptr;
}
