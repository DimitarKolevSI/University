#include "Shop.h"
#include<iostream>

using namespace std;

void Shop::setAmountOfUsers(const int AmountOfUsers)
{
	this->AmountOfUsers = AmountOfUsers;
}

void Shop::setMaxUsers(const int MaxUsers)
{
	this->MaxUsers = MaxUsers;
}

void Shop::setAmountOfGuests(const int AmountOfGuests)
{
	this->AmountOfGuests = AmountOfGuests;
}

void Shop::setMaxGuests(const int MaxGuests)
{
	this->MaxGuests = MaxGuests;
}

void Shop::resizeForUsers()
{
	this->MaxUsers *= 2;
	Registered* temp = new Registered[this->MaxUsers];
	for (int i = 0; i < this->AmountOfUsers; i++) {
		temp[i] = this->Users[i];
	}
	delete[] Users;
	Users = temp;
}

void Shop::resizeForGuests()
{
	this->MaxGuests *= 2;
	Guest* temp = new Guest[this->MaxUsers];
	for (int i = 0; i < this->AmountOfGuests; i++) {
		temp[i] = this->Guests[i];
	}
	delete[] Guests;
	Guests = temp;
}

Shop::Shop()
{
	setAmountOfGuests(0);
	setMaxGuests(10);
	this->Guests = new Guest[MaxGuests];
	setAmountOfUsers(0);
	setMaxUsers(10);
	this->Users = new Registered[MaxUsers];
}

Shop::Shop(const int MaxUsers)
{
	setAmountOfGuests(0);
	setMaxGuests(10);
	this->Guests = new Guest[MaxGuests];
	setAmountOfUsers(0);
	setMaxUsers(MaxUsers);
	this->Users = new Registered[MaxUsers];
}

Shop::Shop(const int MaxUsers, const int MaxGuests)
{
	setAmountOfGuests(0);
	setMaxGuests(MaxGuests);
	this->Guests = new Guest[MaxGuests];
	setAmountOfUsers(0);
	setMaxUsers(MaxUsers);
	this->Users = new Registered[MaxUsers];
}

Shop::Shop(const Shop & copy)
{
	Storage(copy.Products);
	setAmountOfGuests(copy.AmountOfGuests);
	setMaxGuests(copy.MaxGuests);
	this->Guests = new Guest[MaxGuests];
	for (int i = 0; i < AmountOfGuests; i++) {
		copy.Guests[i] = Guests[i];
	}
	setAmountOfUsers(copy.AmountOfUsers);
	setMaxUsers(copy.MaxUsers);
	this->Users = new Registered[MaxUsers];
	for (int i = 0; i < AmountOfUsers; i++) {
		copy.Users[i] = Users[i];
	}
}

const Shop & Shop::operator=(const Shop & copy)
{
	if (this != &copy) 
	{
		delete[] Guests;
		delete[] Users;
		this->Products = copy.Products;
		setAmountOfGuests(copy.AmountOfGuests);
		setMaxGuests(copy.MaxGuests);
		this->Guests = new Guest[MaxGuests];
		for (int i = 0; i < AmountOfGuests; i++) {
			copy.Guests[i] = Guests[i];
		}
		setAmountOfUsers(copy.AmountOfUsers);
		setMaxUsers(copy.MaxUsers);
		this->Users = new Registered[MaxUsers];
		for (int i = 0; i < AmountOfUsers; i++) {
			copy.Users[i] = Users[i];
		}
	}
	return *this;
}

const int Shop::getAmountOfUsers() const
{
	return this->AmountOfUsers;
}

const int Shop::getMaxUsers() const
{
	return this->MaxUsers;
}

const int Shop::getAmountOfGuests() const
{
	return this->AmountOfGuests;
}

const int Shop::getMaxGuests() const
{
	return this->MaxGuests;
}

const Registered Shop::getUserAt(int index)
{
	while(index < 0 || index >= AmountOfUsers) {
		cout << "Invalid index! The amount of users is "<<AmountOfUsers<< "\nNew index: ";
		cin >> index;
	}
	return Users[index];
}

const Guest Shop::getGuestAt(int index)
{
	while (index < 0 || index >= AmountOfUsers) {
		cout << "Invalid index! The amount of users is " << AmountOfUsers << "\nNew index: ";
		cin >> index;
	}
	return Guests[index];
}

void Shop::addGuest(const Guest & newGuest)
{
	if (AmountOfGuests == MaxGuests) resizeForGuests();
	Guests[AmountOfGuests] = newGuest;
	AmountOfGuests++;
}

void Shop::addUser(const Registered & newUser)
{
	if (AmountOfUsers == MaxUsers) resizeForUsers();
	Users[AmountOfUsers] = newUser;
	AmountOfUsers++;
}

void Shop::removeUser(const Registered & user)
{
	int index = -1;
	for (int i = 0; i < AmountOfUsers; i++) {
		if (Users[i].getID() == user.getID()) index = i;
	}
	if (index = -1) return;
	if (index == AmountOfUsers - 1) {
		AmountOfUsers--;
		return;
	}
	for (int i = index; i < AmountOfUsers - 1; i++) {
		Users[i] = Users[i + 1];
	}
}

void Shop::removeGuest(const Guest & guest)
{
	int index = -1;
	for (int i = 0; i < AmountOfGuests; i++) {
		if (Guests[i].getID() == guest.getID()) index = i;
	}
	if (index = -1) return;
	if (index == AmountOfGuests - 1) {
		AmountOfGuests--;
		return;
	}
	for (int i = index; i < AmountOfGuests - 1; i++) {
		Guests[i] = Guests[i + 1];
	}
}

void Shop::RegisterAGuest(const Guest & guest, const char* Username, const char* Password, const char* Email)
{
	Registered user(Username, Password, Email);
	addUser(user);
	removeGuest(guest);
}

void Shop::addProduct(const Product & newProduct)
{
	Products.addProduct(newProduct);
}

void Shop::removeProduct(const Product & product)
{
	Products.removeProduct(product);
}

void Shop::removeProductWithIndex(const int index)
{
	Products.removeProductWithIndex(index);
}

void Shop::printAllProducts() const
{
	Products.printAllProducts();
}

void Shop::addVideoGame(const VideoGame & newVideoGame)
{
	VideoGames.addVideoGame(newVideoGame);
}

void Shop::removeVideoGame(const VideoGame & VideoGame)
{
	VideoGames.removeVideoGame(VideoGame);
}

void Shop::removeVideoGameWithIndex(const int index)
{
	VideoGames.removeVideoGameWithIndex(index);
}

void Shop::printAllVideoGames() const
{
	VideoGames.printAllVideoGames();
}

void Shop::addBook(const Book & newBook)
{
	Books.addBook(newBook);
}

void Shop::removeBook(const Book & Book)
{
	Books.removeBook(Book);
}

void Shop::removeBookWithIndex(const int index)
{
	Books.removeBookWithIndex(index);
}

void Shop::printAllBooks() const
{
	Books.printAllBooks();
}

void Shop::addSmartPhone(const SmartPhone & newSmartPhone)
{
	SmartPhones.addSmartPhone(newSmartPhone);
}

void Shop::removeSmartPhone(const SmartPhone & SmartPhone)
{
	SmartPhones.removeSmartPhone(SmartPhone);
}

void Shop::removeSmartPhoneWithIndex(const int index)
{
	SmartPhones.removeSmartPhoneWithIndex(index);
}

void Shop::printAllSmartPhones() const
{
	SmartPhones.printAllSmartPhones();
}

void Shop::addLaptop(const Laptop & newLaptop)
{
	Laptops.addLaptop(newLaptop);
}

void Shop::removeLaptop(const Laptop & Laptop)
{
	Laptops.removeLaptop(Laptop);
}

void Shop::removeLaptopWithIndex(const int index)
{
	Laptops.removeLaptopWithIndex(index);
}

void Shop::printAllLaptops() const
{
	Laptops.printAllLaptops();
}

Shop::~Shop()
{
	delete[] this->Users;
	this->Users = nullptr;
	delete[] this->Guests;
	this->Guests = nullptr;
}
