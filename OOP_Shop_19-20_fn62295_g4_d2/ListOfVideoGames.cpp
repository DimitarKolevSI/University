#include "ListOfVideoGames.h"
#include<iostream>

using namespace std;

void ListOfVideoGames::setSize(const int Size)
{
	this->Size = Size;
}

void ListOfVideoGames::setMaxSize(const int maxSize)
{
	this->MaxSize = maxSize;
}

void ListOfVideoGames::resize()
{
	this->MaxSize *= 2;
	VideoGame* temp = new VideoGame[this->MaxSize];
	for (int i = 0; i < this->Size; i++) {
		temp[i] = this->VideoGames[i];
	}
	delete[] VideoGames;
	VideoGames = temp;
}

void ListOfVideoGames::shrink()
{
	this->MaxSize /= 2;
	VideoGame* temp = new VideoGame[this->MaxSize];
	for (int i = 0; i < this->Size; i++) {
		temp[i] = this->VideoGames[i];
	}
	delete[] VideoGames;
	VideoGames = temp;
}

ListOfVideoGames::ListOfVideoGames()
{
	setSize(0);
	setMaxSize(1);
	this->VideoGames = new VideoGame[this->MaxSize];
}

ListOfVideoGames::ListOfVideoGames(const int maxSize)
{
	setSize(0);
	setMaxSize(maxSize);
	this->VideoGames = new VideoGame[this->MaxSize];
}

ListOfVideoGames::ListOfVideoGames(const ListOfVideoGames & copy)
{
	setSize(copy.Size);
	setMaxSize(copy.MaxSize);
	this->VideoGames = new VideoGame[this->MaxSize];
	for (int i = 0; i < this->Size; i++) {
		this->VideoGames[i] = copy.VideoGames[i];
	}
}

const ListOfVideoGames & ListOfVideoGames::operator=(const ListOfVideoGames & copy)
{
	if (this != &copy) {
		setSize(copy.Size);
		setMaxSize(copy.MaxSize);
		delete[] VideoGames;
		VideoGames = nullptr;
		this->VideoGames = new VideoGame[this->MaxSize];
		for (int i = 0; i < this->Size; i++) {
			this->VideoGames[i] = copy.VideoGames[i];
		}
	}
	return *this;
}

const int ListOfVideoGames::getSize() const
{
	return Size;
}

const int ListOfVideoGames::getMaxSize() const
{
	return MaxSize;
}

void ListOfVideoGames::addVideoGame(const VideoGame & newVideoGame)
{
	for (int i = 0; i < this->Size; i++) {
		if (strcmp(newVideoGame.getName(), VideoGames[i].getName()) == 0) {
			cout << "This VideoGame is already in the ListOfVideoGames" << endl;
		}
	}
	if (this->Size == this->MaxSize) {
		resize();
	}
	VideoGames[this->Size] = newVideoGame;
	this->Size++;
}

void ListOfVideoGames::removeVideoGame(const VideoGame & VideoGame)
{
	for (int i = 0; i < this->Size; i++) {
		if (VideoGame.getName() == VideoGames[i].getName()) {
			removeVideoGameWithIndex(i);
			return;
		}
	}
}

void ListOfVideoGames::removeVideoGameWithIndex(const int index)
{
	if (index == this->Size) {
		this->Size--;
		return;
	}
	for (int i = index; i < this->Size - 1; i++) {
		VideoGames[i] = VideoGames[i + 1];
	}
	this->Size--;
	if (4 * Size <= MaxSize) shrink();
}

void ListOfVideoGames::printAllVideoGames() const
{
	if (this->Size == 0) {
		cout << "The cart is empty!" << endl;
		return;
	}
	for (int i = 0; i < this->Size; i++) {
		VideoGames[i].print();
	}
}

const double ListOfVideoGames::calculate() const
{
	double bill = 0;
	for (int i = 0; i < this->Size; i++) {
		bill += this->VideoGames[i].getPrice();
	}
	return bill;
}

ListOfVideoGames::~ListOfVideoGames()
{
	delete[] VideoGames;
	VideoGames = nullptr;
}
