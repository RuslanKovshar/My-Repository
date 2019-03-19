#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Letter : public Sprite
{
public:
	Letter(char character, int count, int score);
	Letter();
	~Letter();
	char getCharacter();
	int getCount();
	int getScore();
	void setCharacter(char character);
	void setCount(int count);
	void setScore(int score);
	void setActive(bool Active);
	bool getActive();
	friend ostream& operator<<(ostream& str,const Letter letter);

private:
	char character;
	int count;
	int score;
	bool isActive;
};

