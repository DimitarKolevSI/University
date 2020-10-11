#include<iostream>
#include "Laptop.h"
#include "VideoGame.h"
#include "Book.h"
#include "Smartphone.h"
#include "Registered.h"
#include <conio.h>

using namespace std;

int main()
{
	/*Laptop acer("Acer", "Aspire", "Laptop", 1500, 15);
	char com;
	system("pause");
	Laptop* laptops = new Laptop[50000];
	

	//cin >> com;
	for (int i = 0; i < 50000; i++)
	{
		laptops[i] = acer;
		//cout << i << endl;
	}
	//cin >> com;
	Laptop newAcer = acer;
	cout << acer.getBrand() << endl;
	cout << acer.getModel() << endl;
	cout << acer.getCategory() << endl;
	cout << "Start deleting?" << endl;
	cin >> com;
	delete[] laptops;
	laptops = nullptr;
	cout << "Deleted everything" << endl;
	cin >> com;
	laptops = new Laptop[5000];
	for (int i = 0; i < 5000; i++)
	{
		cout << i << endl;
	}
	system("pause");
	delete[] laptops;
	laptops = nullptr;*/
	/*VideoGame spiderMan("The Amazing Spider-man", "Sony", "PS4", 2018, 60, 50);
	VideoGame spiderE = spiderMan;
	spiderMan.print();
	spiderMan.rateTheGame(10);
	spiderMan.rateTheGame(0);
	spiderMan.increaseAmount(10);
	spiderMan.decreaseAmount(20);
	spiderMan.increasePrice(12.5);
	spiderMan.decreasePrice(15);
	spiderMan.print();
	VideoGame spiderC(spiderMan);
	cout << "SpiderE: " << endl;
	spiderE.print();
	cout << "SpiderC: " << endl;
	spiderC.print();*/
	/*Book ad("Inferno", "Dan Brown", "Thriller", 500, 21.50, 30, 2017);
	ad.print();
	ad.rateTheBook(10);
	ad.rateTheBook(5);
	ad.rateTheBook(0);
	ad.rateTheBook(10);
	cout << endl;
	ad.print();
	ad.increaseAmount(50);
	cout << endl;
	ad.print();
	ad.increasePrice(3.50);
	cout << endl;
	ad.print();*/
	/*SmartPhone ad("Samsung", "S10+", 1500, 15, 2019);
	ad.print();
	ad.rateTheSmartPhone(10);
	ad.rateTheSmartPhone(6);
	ad.rateTheSmartPhone(0);
	ad.rateTheSmartPhone(10);
	cout << endl;
	ad.print();
	ad.decreaseAmount(3);
	cout << endl;
	ad.print();
	ad.decreasePrice(100);
	cout << endl;
	ad.print();
	system("pause");
	SmartPhone* s = new SmartPhone[5000];
	Laptop* l = new Laptop[5000];
	VideoGame* v = new VideoGame[5000];
	Book* b = new Book[5000];
	system("pause");
	delete[] s;
	delete[] l;
	delete[] v;
	delete[] b;*/
	/*char pswrd[5];

	int i = 0;
	while ((pswrd[i] = _getch()) != '\r'||i==5)
	{
		cout << "*";
		i++;
	}
	cout << endl;
	for (int j = 0; j < i; j++) cout << pswrd[j];
	cout << endl;*/
	Registered me("Dimitar", "123456789", "abv@abv.bg");
	cout << me.getUsername() << endl;
	cout << me.getEmail() << endl;
	me.changePassword();
	me.logIn();
	me.changePassword();
	me.logOut();
	me.logIn();
	system("pause");
	return 0;
}