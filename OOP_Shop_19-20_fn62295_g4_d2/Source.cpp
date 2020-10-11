#include <iostream>
#include "Shop.h"
#include "ListOfBooks.h"

using namespace std;

int main() 
{
	/*Book Inferno("Inferno", "Dan Brown", "Thriller", 500,21.50,50,2018);
	Book Origin("Origin", "Dan Brown", "Thriller", 550, 24, 50, 2018);
	ListOfBooks library;
	system("pause");
	for (int i = 0; i < 40000; i++) {
		cout << i << endl;
		library.addBook(Inferno);
		library.addBook(Origin);
	}
	system("pause");
	library.~ListOfBooks();
	cout << "No more testing" << endl;*/
	/*Product acer(2015, 20, 15);
	Product lenovo(2018, 1000, 10);
	Product asus(2017, 150, 20);
	Product acer2(2019, 1000, 25);
	Registered me("Dimitar", "123456789", "me@abv.bg");
	Shop s;
	s.addUser(me);
	s.getUserAt(0).print();
	Guest g;
	s.addGuest(g);
	s.RegisterAGuest(g, "Ivana", "123456", "she@abv.bg");
	s.getUserAt(0).print();
	s.getUserAt(1).print();
	s.removeUser(me);
	s.getUserAt(0).print();*/
	Registered r;
	Book ad("Inferno", "Dan Brown", "Thriller", 500, 21.50, 50, 2018);
	Laptop acer("Acer", "Aspire", "Home", 1500, 10, 2019);
	SmartPhone samsung("Samsung", "S20", 2800, 10, 2020);
	VideoGame spiderman("Spider-man", "Sony", "PS4", 2018, 40, 10);
	r.addBookToShoppingCart(ad);
	r.addLaptopToShoppingCart(acer);
	r.addSmartPhoneToShoppingCart(samsung);
	r.addVideoGameToShoppingCart(spiderman);
	r.removeSmartPhoneFromShoppingCart(samsung);
	cout << endl << r.pay() << endl;
	system("pause");
	return 0;
}