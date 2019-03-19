#pragma once
#include "Letter.h"
#include <vector>

using namespace std;

class Player
{
public:
	Player();
	~Player();
	void setPasses();
	void setScore(int playerScore);
	void setUpdateCharackter(int i);
	void setPlayerCharackter(Texture &letterTexture, string& letterCounter);
	int getPlayerScore();
	int getPasses();
	vector<int>& getUpdateCharackters();
	vector<Letter>& getLetter();
private:
	int playerScore;
	int passes;
	vector<Letter> letter;
	vector<int> updateCharackter;
};

