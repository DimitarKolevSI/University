#pragma once
#include "VideoGame.h"
class ListOfVideoGames
{
private:
	VideoGame* VideoGames = nullptr;
	int Size;
	int MaxSize;

	void setSize(const int Size);
	void setMaxSize(const int MaxSize);
	void resize();
	void shrink();
public:
	ListOfVideoGames();
	ListOfVideoGames(const int MaxSize);
	ListOfVideoGames(const ListOfVideoGames& copy);
	const ListOfVideoGames& operator=(const ListOfVideoGames&);

	const int getSize() const;
	const int getMaxSize() const;

	void addVideoGame(const VideoGame& newVideoGame);
	void removeVideoGame(const VideoGame& VideoGame);
	void removeVideoGameWithIndex(const int index);
	void printAllVideoGames() const;
	const double calculate() const;

	~ListOfVideoGames();
};