#include <iostream>
#include "Shop.h"

using namespace std;

int main()
{
	/*for (int i = 0; i < 100; i++) ints.add(i);
	cout << "Size: " << ints.getSize() << endl;
	cout << "Max size: " << ints.getMaxSize() << endl;
	cout << "Elements before remove: \n";
	for (int i = 0; i < 100; i++) cout << ints.getAt(i) << "  ";
	cout << endl;
	for (int i = 0; i < 70; i++) ints.remove(i);
	cout << "Size: " << ints.getSize() << endl;
	cout << "Max size: " << ints.getMaxSize() << endl;
	cout << "Elements after remove: \n";
	for (int i = 0; i < 30; i++) cout << ints.getAt(i) << "  ";
	cout << endl;
	cout << "Is empty: " << ints.isEmpty() << endl;
	ints.empty();
	cout << "Size: " << ints.getSize() << endl;
	cout << "Max size: " << ints.getMaxSize() << endl;
	cout << "Is empty: " << ints.isEmpty() << endl;*/
	/*cout << "Start?";
	cin >> command;
	for (int i = 0; i < 5000000; i++) ints.add(i);
	cout << "Size: " << ints.getSize() << endl;
	cout << "Max size: " << ints.getMaxSize() << endl;
	cout << "Countinue?";
	cin >> command;
	ints.empty();
	cout << "Size: " << ints.getSize() << endl;
	cout << "Max size: " << ints.getMaxSize() << endl;*/

	Shop myShop;
	VideoGame v("Spiderman", "Sony", "PS4", 2018, 50, 10);
	SmartPhone s("Samsung", "S10", 2000.0, 10, 2019);
	Product p;
	Book b("Inferno", "Dan Brown", "Thriller", 500, 21.50, 15, 2019);
	Laptop l("Acer", "Aspire 5", "home", 1600, 10, 2018);
	Registered user("me", "123456", "me@abv.bg");
	user.logIn();
	user.addSmartPhoneToShoppingCart(s);
	user.addVideoGameToShoppingCart(v);
	cout << user.pay()<<endl;
	cout << v << endl;
	cout << s << endl;
	cout << p << endl;
	cout << b << endl;
	cout << l << endl;
	system("pause");
	
	return 0; 
}