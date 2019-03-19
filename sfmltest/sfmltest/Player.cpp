#include "Player.h"
#include "Letter.h"


int letterInUse(string letterCounter, char letter)
{
	int counter = 0;
	for (int i = 0; i < letterCounter.length(); i++)
	{
		if (letterCounter[i] == letter)
		{
			counter++;
		}
	}
	return counter;
}

Player::Player()
{
	playerScore = 0;
	passes = 0;
	letter.resize(8);
	updateCharackter = { 0,1,2,3,4,5,6 };
}


Player::~Player()
{
}

void Player::setPasses()
{
	this->passes++;
}

void Player::setScore(int playerScore)
{
	this->playerScore += playerScore;
}

void Player::setUpdateCharackter(int i)
{
	updateCharackter.insert(updateCharackter.end(), i);
}

void Player::setPlayerCharackter(Texture& letterTexture, string& letterCounter)
{
	int x, y;
	int Char;
	int i;
	for (int j = 0; j < updateCharackter.size(); j++)
	{
		i = updateCharackter[j];
		letter[i].setActive(true);
		letter[i].setTexture(letterTexture);
		letter[i].setScale(0.6, 0.6);
		letter[i].setPosition(60 * (i + 1), 825);
		Char = rand() % 26 + 65;
		switch (Char)
		{
			//case 65: x = 0; y = 0; letter[i].setCount(9 - letterInUse(letterCounter, 'A')); letter[i].setScore(1); letterCounter.append("A"); break;
		case 65: x = 0; y = 0; cout << "!!!" << endl; updateCharackter.insert(updateCharackter.end(), i); break;

		case 66: x = 1; y = 0; letter[i].setCount(2 - letterInUse(letterCounter, 'B')); letter[i].setScore(3); letterCounter.append("B"); break;
		case 67: x = 2; y = 0; letter[i].setCount(2 - letterInUse(letterCounter, 'C')); letter[i].setScore(3); letterCounter.append("C"); break;
		case 68: x = 3; y = 0; letter[i].setCount(4 - letterInUse(letterCounter, 'D')); letter[i].setScore(2); letterCounter.append("D"); break;
		case 69: x = 4; y = 0; letter[i].setCount(12 - letterInUse(letterCounter, 'E')); letter[i].setScore(1); letterCounter.append("E"); break;
		case 70: x = 5; y = 0; letter[i].setCount(2 - letterInUse(letterCounter, 'F')); letter[i].setScore(4); letterCounter.append("F"); break;
		case 71: x = 6; y = 0; letter[i].setCount(3 - letterInUse(letterCounter, 'G')); letter[i].setScore(2); letterCounter.append("G"); break;

		case 72: x = 0; y = 1; letter[i].setCount(2 - letterInUse(letterCounter, 'H')); letter[i].setScore(4); letterCounter.append("H"); break;
		case 73: x = 1; y = 1; letter[i].setCount(9 - letterInUse(letterCounter, 'I')); letter[i].setScore(1); letterCounter.append("I"); break;
		case 74: x = 2; y = 1; letter[i].setCount(1 - letterInUse(letterCounter, 'J')); letter[i].setScore(8); letterCounter.append("J"); break;
		case 75: x = 3; y = 1; letter[i].setCount(1 - letterInUse(letterCounter, 'K')); letter[i].setScore(5); letterCounter.append("K"); break;
		case 76: x = 4; y = 1; letter[i].setCount(4 - letterInUse(letterCounter, 'L')); letter[i].setScore(1); letterCounter.append("L"); break;
		case 77: x = 5; y = 1; letter[i].setCount(2 - letterInUse(letterCounter, 'M')); letter[i].setScore(3); letterCounter.append("M"); break;
		case 78: x = 6; y = 1; letter[i].setCount(6 - letterInUse(letterCounter, 'N')); letter[i].setScore(1); letterCounter.append("N"); break;

		case 79: x = 0; y = 2; letter[i].setCount(8 - letterInUse(letterCounter, 'O')); letter[i].setScore(1); letterCounter.append("O"); break;
		case 80: x = 1; y = 2; letter[i].setCount(2 - letterInUse(letterCounter, 'P')); letter[i].setScore(3); letterCounter.append("P"); break;
		case 81: x = 2; y = 2; letter[i].setCount(1 - letterInUse(letterCounter, 'Q')); letter[i].setScore(10); letterCounter.append("Q"); break;
		case 82: x = 3; y = 2; letter[i].setCount(6 - letterInUse(letterCounter, 'R')); letter[i].setScore(1); letterCounter.append("R"); break;
		case 83: x = 4; y = 2; letter[i].setCount(4 - letterInUse(letterCounter, 'S')); letter[i].setScore(1); letterCounter.append("S"); break;
		case 84: x = 5; y = 2; letter[i].setCount(6 - letterInUse(letterCounter, 'T')); letter[i].setScore(1); letterCounter.append("T"); break;
		case 85: x = 6; y = 2; letter[i].setCount(4 - letterInUse(letterCounter, 'U')); letter[i].setScore(1); letterCounter.append("U"); break;

		case 86: x = 0; y = 3; letter[i].setCount(2 - letterInUse(letterCounter, 'V')); letter[i].setScore(4); letterCounter.append("V"); break;
		case 87: x = 1; y = 3; letter[i].setCount(2 - letterInUse(letterCounter, 'W')); letter[i].setScore(4); letterCounter.append("W"); break;
		case 88: x = 2; y = 3; letter[i].setCount(1 - letterInUse(letterCounter, 'X')); letter[i].setScore(8); letterCounter.append("X"); break;
		case 89: x = 3; y = 3; letter[i].setCount(2 - letterInUse(letterCounter, 'Y')); letter[i].setScore(4); letterCounter.append("Y"); break;
		case 90: x = 4; y = 3; letter[i].setCount(1 - letterInUse(letterCounter, 'Z')); letter[i].setScore(10); letterCounter.append("Z"); break;
		default:break;
		}
		letter[i].setCharacter((char)Char);
		letter[i].setTextureRect(IntRect(91 * x, 91 * y, 83, 83));
	}
	cout << letterCounter << endl;
}

int Player::getPlayerScore()
{
	return playerScore;
}

int Player::getPasses()
{
	return passes;
}

vector<int>& Player::getUpdateCharackters()
{
	return updateCharackter;
}

vector<Letter>& Player::getLetter()
{
	return letter;
}


