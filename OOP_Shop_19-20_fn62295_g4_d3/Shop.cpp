#include "Shop.h"
#include<iostream>

using namespace std;

Shop::Shop() : Books(), Laptops(), SmartPhones(), VideoGames(), Products(),
			   Users(), Guests()
{
	
}

Shop::Shop(const int MaxUsers) : Books(), Laptops(), SmartPhones(), VideoGames(), Products(),
								 Users(MaxUsers), Guests()
{

}

Shop::Shop(const int MaxUsers, const int MaxGuests) : Books(), Laptops(), SmartPhones(), VideoGames(), Products(),
													  Users(MaxUsers), Guests(MaxGuests)
{

}

Shop::Shop(const Shop & copy)
{
	Books = copy.Books;
	Laptops = copy.Laptops;
	SmartPhones = copy.SmartPhones;
	VideoGames = copy.VideoGames;
	Products = copy.Products;
	Users = copy.Users;
	Guests = copy.Guests;
}

const Shop & Shop::operator=(const Shop & copy)
{
	if (this != &copy)
	{
		Books = copy.Books;
		Laptops = copy.Laptops;
		SmartPhones = copy.SmartPhones;
		VideoGames = copy.VideoGames;
		Products = copy.Products;
		Users = copy.Users;
		Guests = copy.Guests;
	}
	return *this;
}

const int Shop::getAmountOfUsers() const
{
	return this->Users.getSize();
}
const int Shop::getAmountOfGuests() const
{
	return this->Guests.getSize();
}

const Registered Shop::getUserAt(int index)
{
	return Users.getAt(index);
}

const Guest Shop::getGuestAt(int index)
{
	return Guests.getAt(index);
}

void Shop::addGuest(const Guest & newGuest)
{
	Guests.add(newGuest);
}

void Shop::addUser(const Registered & newUser)
{
	Users.add(newUser);
}

void Shop::removeUser(const Registered & user)
{
	Users.remove(user);
}

void Shop::removeGuest(const Guest & guest)
{
	Guests.remove(guest);
}

void Shop::RegisterAGuest(const Guest & guest, const char* Username, const char* Password, const char* Email)
{
	Registered user(Username, Password, Email);
	addUser(user);
	removeGuest(guest);
}

void Shop::addProduct(const Product & newProduct)
{
	Products.add(newProduct);
}

void Shop::removeProduct(const Product & product)
{
	Products.remove(product);
}

void Shop::removeProductWithIndex(const int index)
{
	Products.removeWithIndex(index);
}

void Shop::printAllProducts() const
{
	Products.print();
}

void Shop::addVideoGame(const VideoGame & newVideoGame)
{
	VideoGames.add(newVideoGame);
}

void Shop::removeVideoGame(const VideoGame & VideoGame)
{
	VideoGames.remove(VideoGame);
}

void Shop::removeVideoGameWithIndex(const int index)
{
	VideoGames.removeWithIndex(index);
}

void Shop::printAllVideoGames() const
{
	VideoGames.print();
}

void Shop::addBook(const Book & newBook)
{
	Books.add(newBook);
}

void Shop::removeBook(const Book & Book)
{
	Books.remove(Book);
}

void Shop::removeBookWithIndex(const int index)
{
	Books.removeWithIndex(index);
}

void Shop::printAllBooks() const
{
	Books.print();
}

void Shop::addSmartPhone(const SmartPhone & newSmartPhone)
{
	SmartPhones.add(newSmartPhone);
}

void Shop::removeSmartPhone(const SmartPhone & SmartPhone)
{
	SmartPhones.remove(SmartPhone);
}

void Shop::removeSmartPhoneWithIndex(const int index)
{
	SmartPhones.removeWithIndex(index);
}

void Shop::printAllSmartPhones() const
{
	SmartPhones.print();
}

void Shop::addLaptop(const Laptop & newLaptop)
{
	Laptops.add(newLaptop);
}

void Shop::removeLaptop(const Laptop & Laptop)
{
	Laptops.remove(Laptop);
}

void Shop::removeLaptopWithIndex(const int index)
{
	Laptops.removeWithIndex(index);
}

void Shop::printAllLaptops() const
{
	Laptops.print();
}

Shop::~Shop()
{

}
