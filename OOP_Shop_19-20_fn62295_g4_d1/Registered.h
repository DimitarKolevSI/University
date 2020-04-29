#pragma once
class Registered
{
private:
	char* Username = nullptr;
	char* Password = nullptr;
	char* Email = nullptr;
	bool loggedIn;
	//Things to be added:
	//Shopping cart
	//Hstory of purcheses

	void setUsername(const char* Username);
	void setPassword(const char* Password);
	void setEmail(const char* Email);
	const char* getPassword() const;
	void switchLog();

public:

	Registered();
	Registered(const char* Username, const char* Password, const char* Email);
	Registered(const Registered& oldUser);
	Registered& operator=(const Registered& oldUser);

	const char* getUsername() const;
	const char* getEmail() const;
	void changePassword();
	void logIn();
	void logOut();

	//Methods to be added:
	//Add product to the cart
	//Remove product from the cart
	//pay
	//

	~Registered();

};