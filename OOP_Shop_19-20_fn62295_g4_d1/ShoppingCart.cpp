#include "ShoppingCart.h"

void ShoppingCart::setSize(const int Size)
{
	this->Size = Size;
}

void ShoppingCart::setMaxSize(const int maxSize)
{
	this->MaxSize = maxSize;
}

ShoppingCart::ShoppingCart()
{
	setSize(0);
	setMaxSize(10);
}

ShoppingCart::ShoppingCart(const int maxSize)
{
	setSize(0);
	setMaxSize(maxSize);
}

const int ShoppingCart::getSize() const
{
	return this->Size;
}

const int ShoppingCart::getMaxSize() const
{
	return this->MaxSize;
}
