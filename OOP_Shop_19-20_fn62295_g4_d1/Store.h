#pragma once
class Store
{
private:

	char* Name = nullptr;
	void setName(const char* Name);
	//Variables to be added:
	//List of users,
	//List of products
	
public:

	Store();
	Store(const char* Name);
	Store(const Store& copyStore);
	Store& operator=(const Store& copyStore);

	const char* getName() const;
	//Functions to be added
	//addUser
	//removeUser
	//printInvertory
	//displayByCategory
	//sortByPrice
	//addProduct
	//removeProduct
	//addAmountToAProduct
	//sortByRating
	//Discount on everything
	//Discount by category

	~Store();
};