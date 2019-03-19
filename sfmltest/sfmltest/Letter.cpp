#include <SFML/Graphics.hpp>
#include "Letter.h"
#include <iostream>

using namespace std;


Letter::Letter(char character,int count,int score)
{
	this->character = character;
	this->count = count;
	this->score = score;
	isActive = true;
}

Letter::Letter()
{
	character = '.';
	count = 0;
	score = 0;
	isActive = true;
}


Letter::~Letter()
{
}

char Letter::getCharacter()
{
	return character;
}

int Letter::getCount()
{
	return count;
}

int Letter::getScore()
{
	return score;
}

void Letter::setCharacter(char character)
{
	this->character = character;
}

void Letter::setCount(int count)
{
		this->count = count;
	
}

void Letter::setScore(int score)
{
	this->score = score;
}

void Letter::setActive(bool Active)
{
	isActive = Active;
}

bool Letter::getActive()
{
	return isActive;
}

ostream& operator<<(ostream& str,const Letter letter)
{
	cout << letter.character << endl;
	cout << letter.score << endl << endl;
	return str;
}
