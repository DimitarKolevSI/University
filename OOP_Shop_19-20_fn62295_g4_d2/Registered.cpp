#include "Registered.h"
#include  <cstring>
#include <iostream>
#include <conio.h>

using namespace std;

int IDHelper = 30000;
void Registered::setID()
{
	ID = IDHelper;
	IDHelper++;
}

void Registered::setUsername(const char * Username)
{
	if (this->Username != nullptr) delete[] this->Username;
	this->Username = new char[strlen(Username) + 1];
	strcpy_s(this->Username, strlen(Username) + 1, Username);
}

void Registered::setPassword(const char * Password)
{
	if (this->Password != nullptr) delete[] this->Password;
	this->Password = new char[strlen(Password) + 1];
	strcpy_s(this->Password, strlen(Password) + 1, Password);
}

void Registered::setEmail(const char * Email)
{
	if (this->Email != nullptr) delete[] this->Email;
	this->Email = new char[strlen(Email) + 1];
	strcpy_s(this->Email, strlen(Email) + 1, Email);
}

const char * Registered::getPassword() const
{
	return this->Password;
}

void Registered::switchLog()
{
	if (this->loggedIn) loggedIn = false;
	else loggedIn = true;
}

Registered::Registered()
{
	setID();
	setUsername("\0");
	setPassword("\0");
	setEmail("\0");
	loggedIn = false;
}

Registered::Registered(const char * Username, const char * Password, const char* Email)
{
	setID();
	setUsername(Username);
	setPassword(Password);
	setEmail(Email);
	loggedIn = false;
}

Registered::Registered(const Registered & oldUser)
{
	setID();
	setUsername(oldUser.Username);
	setPassword(oldUser.Password);
	setEmail(oldUser.Email);
	loggedIn = oldUser.loggedIn;
}

Registered & Registered::operator=(const Registered & oldUser)
{
	if (this != &oldUser)
	{
		setUsername(oldUser.Username);
		setPassword(oldUser.Password);
		setEmail(oldUser.Email);
		loggedIn = oldUser.loggedIn;
	}
	return *this;
}

const char * Registered::getUsername() const
{
	return this->Username;
}

const char * Registered::getEmail() const
{
	return this->Email;
}

const int Registered::getID() const
{
	return ID;
}

void Registered::changePassword()
{
	if (!loggedIn)
	{
		cout << "You have to log in first!\n";
		return;
	}
	int length;
	cout << "\nThe length of the old password-> ";
	cin >> length;
	if (length > strlen(this->Password))
	{
		cout << "This length is too long for the password!\n";
		return;
	}
	else if (length < strlen(this->Password))
	{
		cout << "This length is too short for the password!\n";
		return;
	}
	char* passwordH = new char[length + 1];
	cout << "\nThe old password-> ";
	int i = 0;
	while ((passwordH[i] = _getch()) != '\r')
	{
		cout << "*";
		i++;
	}
	passwordH[length] = '\0';
	if (!strcmp(Password, passwordH))
	{
		cout << "\nThe length of the new password-> ";
		cin >> length;
		delete[] passwordH;
		passwordH = new char[length + 1];
		cout << "\nThe new password-> ";
		int i = 0;
		while ((passwordH[i] = _getch()) != '\r')
		{
			cout << "*";
			i++;
		}
		passwordH[length] = '\0';
		setPassword(passwordH);
	}
	else
	{
		cout << "/nWrong password!/n" << endl;
	}
	delete[] passwordH;
}

void Registered::logIn()
{
	if (loggedIn)
	{
		cout << "\nYou are already logged in!\n";
		return;
	}
	cout << "\nThe length of the password-> ";
	int length;
	cin >> length;
	char*passwordH = new char[length + 1];
	cout << "\nPassword-> ";
	int i = 0;
	while ((passwordH[i] = _getch()) != '\r')
	{
		cout << "*";
		i++;
	}
	passwordH[length] = '\0';
	if (!strcmp(Password, passwordH))
	{
		loggedIn = true;
		cout << "\nYou have logged in successfully\n";
	}
	else cout << "\nWrong password\n";
	delete[] passwordH;
}

void Registered::logOut()
{
	loggedIn = false;
}

void Registered::addProductToShoppingCart(const Product & newProduct)
{
	this->shoppingCart.addProduct(newProduct);
}

void Registered::removeProductFromShoppingCart(const Product & product)
{
	this->shoppingCart.removeProduct(product);
}

void Registered::removeProductFromShoppingCartWithIndex(const int index)
{
	this->shoppingCart.removeProductWithIndex(index);
}

void Registered::addBookToShoppingCart(const Book & newBook)
{
	this->shoppingCart.addBook(newBook);
}

void Registered::removeBookFromShoppingCart(const Book & Book)
{
	this->shoppingCart.removeBook(Book);
}

void Registered::removeBookFromShoppingCartWithIndex(const int index)
{
	this->shoppingCart.removeBookWithIndex(index);
}

void Registered::addLaptopToShoppingCart(const Laptop & newLaptop)
{
	this->shoppingCart.addLaptop(newLaptop);
}

void Registered::removeLaptopFromShoppingCart(const Laptop & Laptop)
{
	this->shoppingCart.removeLaptop(Laptop);
}

void Registered::removeLaptopFromShoppingCartWithIndex(const int index)
{
	this->shoppingCart.removeLaptopWithIndex(index);
}

void Registered::addSmartPhoneToShoppingCart(const SmartPhone & newSmartPhone)
{
	this->shoppingCart.addSmartPhone(newSmartPhone);
}

void Registered::removeSmartPhoneFromShoppingCart(const SmartPhone & SmartPhone)
{
	this->shoppingCart.removeSmartPhone(SmartPhone);
}

void Registered::removeSmartPhoneFromShoppingCartWithIndex(const int index)
{
	this->shoppingCart.removeSmartPhoneWithIndex(index);
}

void Registered::addVideoGameToShoppingCart(const VideoGame & newVideoGame)
{
	this->shoppingCart.addVideoGame(newVideoGame);
}

void Registered::removeVideoGameFromShoppingCart(const VideoGame & VideoGame)
{
	this->shoppingCart.removeVideoGame(VideoGame);
}

void Registered::removeVideoGameFromShoppingCartWithIndex(const int index)
{
	this->shoppingCart.removeVideoGameWithIndex(index);
}

double Registered::pay()
{
	return shoppingCart.emptyTheCart();
}

void Registered::print() const
{
	cout << "ID: " << ID << endl;
	cout << "Email: " << Email << endl;
	cout << "Username: " << Username << endl;
}

Registered::~Registered()
{
	delete[] this->Email;
	delete[] this->Username;
	delete[] this->Password;
	this->Email = nullptr;
	this->Username = nullptr;
	this->Password = nullptr;
}
