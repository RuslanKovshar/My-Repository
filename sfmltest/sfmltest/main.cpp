#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <ctime>
#include "Letter.h"
#include "Player.h"
#include <vector>
#include <string>


using namespace sf;
using namespace std;


void getTexture(Letter* letter, Player& player, Texture& letterTexture)
{
	int x, y;
	int Char;
	int i;
	for (int j = 0; j < player.getUpdateCharackters().size(); j++)
	{
		i = player.getUpdateCharackters()[j];
		letter[i].setActive(true);
		letter[i].setTexture(letterTexture);
		letter[i].setScale(0.6, 0.6);
		letter[i].setPosition(60 * (i + 1), 850);
		Char = rand() % 26 + 65;
		switch (Char)
		{
		case 65: x = 0; y = 0; letter[i].setCount(9); letter[i].setScore(1); break;
		case 66: x = 1; y = 0; letter[i].setCount(2); letter[i].setScore(3); break;
		case 67: x = 2; y = 0; letter[i].setCount(2); letter[i].setScore(3); break;
		case 68: x = 3; y = 0; letter[i].setCount(4); letter[i].setScore(2); break;
		case 69: x = 4; y = 0; letter[i].setCount(12); letter[i].setScore(1); break;
		case 70: x = 5; y = 0; letter[i].setCount(2); letter[i].setScore(4); break;
		case 71: x = 6; y = 0; letter[i].setCount(3); letter[i].setScore(2); break;

		case 72: x = 0; y = 1; letter[i].setCount(2); letter[i].setScore(4); break;
		case 73: x = 1; y = 1; letter[i].setCount(9); letter[i].setScore(1); break;
		case 74: x = 2; y = 1; letter[i].setCount(1); letter[i].setScore(8); break;
		case 75: x = 3; y = 1; letter[i].setCount(1); letter[i].setScore(5); break;
		case 76: x = 4; y = 1; letter[i].setCount(4); letter[i].setScore(1); break;
		case 77: x = 5; y = 1; letter[i].setCount(2); letter[i].setScore(3); break;
		case 78: x = 6; y = 1; letter[i].setCount(6); letter[i].setScore(1); break;

		case 79: x = 0; y = 2; letter[i].setCount(8); letter[i].setScore(1); break;
		case 80: x = 1; y = 2; letter[i].setCount(2); letter[i].setScore(3); break;
		case 81: x = 2; y = 2; letter[i].setCount(1); letter[i].setScore(10); break;
		case 82: x = 3; y = 2; letter[i].setCount(6); letter[i].setScore(1); break;
		case 83: x = 4; y = 2; letter[i].setCount(4); letter[i].setScore(1); break;
		case 84: x = 5; y = 2; letter[i].setCount(6); letter[i].setScore(1); break;
		case 85: x = 6; y = 2; letter[i].setCount(4); letter[i].setScore(1); break;

		case 86: x = 0; y = 3; letter[i].setCount(2); letter[i].setScore(4); break;
		case 87: x = 1; y = 3; letter[i].setCount(2); letter[i].setScore(4); break;
		case 88: x = 2; y = 3; letter[i].setCount(1); letter[i].setScore(8); break;
		case 89: x = 3; y = 3; letter[i].setCount(2); letter[i].setScore(4); break;
		case 90: x = 4; y = 3; letter[i].setCount(1); letter[i].setScore(10); break;
		default:break;
		}
		letter[i].setCharacter((char)Char);
		letter[i].setTextureRect(IntRect(91 * x, 91 * y, 83, 83));
	}
	//player.getUpdateCharackters().clear();
}

void output(char Field[15][15])
{
	system("cls");
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			cout << Field[i][j] << "  |";
		}
		cout << endl;
	}
}

string str(int player)
{
	stringstream ss;
	ss << player;
	return ss.str();
}

bool check2LMultiplie(int x, int y)
{
	switch (y)
	{
	case 0: if (x == 3 || x == 11) return true; break;
	case 2: if (x == 6 || x == 8) return true; break;
	case 3: if (x == 0 || x == 7 || x == 14) return  true; break;
	case 6: if (x == 2 || x == 6 || x == 8 || x == 12) return  true; break;
	case 7: if (x == 3 || x == 11) return  true; break;
	case 8: if (x == 2 || x == 6 || x == 8 || x == 12) return  true; break;
	case 11: if (x == 0 || x == 7 || x == 14) return  true; break;
	case 12: if (x == 6 || x == 8) return  true; break;
	case 14: if (x == 3 || x == 11) return  true; break;
	default:break;
	}
	return false;
}

bool check3LMultiplie(int x, int y)
{
	switch (y)
	{
	case 1: if (x == 5 || x == 9) return true; break;
	case 5: if (x == 1 || x == 5 || x == 9 || x == 13) return true; break;
	case 9: if (x == 1 || x == 5 || x == 9 || x == 13) return true; break;
	case 13: if (x == 5 || x == 9) return true; break;
	default:break;
	}
	return false;
}

bool check2WMultiplie(int x, int y)
{
	if ((y > 0 && y < 5 || y > 9 && y < 14) && (y == x || y == 14 - x))
	{
		return true;
	}
	return false;
}

bool check3WMultiplie(int x, int y)
{
	switch (y)
	{
	case 0:if (x == 0 || x == 7 || x == 14) return true; break;
	case 7:if (x == 0 || x == 14) return true; break;
	case 14:if (x == 0 || x == 7 || x == 14) return true; break;
	default:break;
	}
	return false;
}

bool check(char Field[15][15], int x, int y, bool firstMove)
{
	if (firstMove)
	{
		if (x == 7 || y == 7)
		{
			return true;
		}
		return false;
	}
	if (Field[y][x] == '.' && (x < 15 && y < 15))
	{
	/*	if (x == 0  && Field[y][x + 1] != '.')
		{
			return true;
		}
		if (x == 14 && Field[y][x - 1] != '.')
		{
			return true;
		}*/
	/*	if (y == 0 && Field[y + 1][x] == '.')
		{
			return false;
		}
		if (y == 14)
		{
			if (Field[y - 1][x] == '.')
			{
				return false;
			}

		}*/
		if (Field[y - 1][x] != '.' || Field[y + 1][x] != '.' || Field[y][x - 1] != '.' || Field[y][x + 1] != '.')
		{
			return true;
		}
	}

	return false;
}

///Проверка на добавление буквы

int main()
{
	srand(time(NULL));
	bool isMove = false;//переменная для щелчка мыши по спрайту
	bool firstMove = true;
	bool wordX2 = false;
	bool wordX3 = false;
	float dX = 0;//корректировка нажатия по х
	float dY = 0;//по у
	int i = -1;
	int setX = 0;
	int setY = 0;
	const int countOfPlayers = 2;
	int player = 0;
	int countOfSprites = 0;
	int score = 0;
	string letterCounter = "";
	Player* players = new Player[countOfPlayers];
	Clock clock;
	char Field[15][15];
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			Field[i][j] = '.';
		}
	}
	RenderWindow window(VideoMode(1600, 900), "SFMLtest");
	Font font;
	font.loadFromFile("fonts\\Regular.ttf");
	Text text("Submit", font, 30);
	text.setPosition(950, 700);
	Text PlayerText;
	PlayerText.setFont(font);
	PlayerText.setCharacterSize(40);
	PlayerText.setString("Player " + str(player + 1) + " \nis playing!");
	PlayerText.setPosition(950, 300);
	Text PlayerScore("Score: " + str(players[player].getPlayerScore()), font, 40);
	PlayerScore.setPosition(950, 450);
	Texture texture;
	texture.loadFromFile("images\\scrabble1.png");
	Texture backgroundTexture;
	backgroundTexture.loadFromFile("images\\background.jpg");
	Texture backButtonTexture;
	backButtonTexture.loadFromFile("images\\back2.png");
	Sprite background;
	background.setTexture(backgroundTexture);
	Sprite gameField;
	gameField.setTexture(texture);
	Sprite backButton;
	backButton.setTexture(backButtonTexture);
	backButton.setPosition(1000, 500);
	backButton.setScale(0.5, 0.5);
	Texture letterTexture;
	letterTexture.loadFromFile("images\\letters1.jpg");
	vector<Letter> drawableLetters;
	drawableLetters.reserve(10);
	vector<Letter> temp;
	temp.reserve(8);
	for (int i = 0; i < 2; i++)
	{
		//getTexture(letter,players[i], letterTexture);
		players[i].setPlayerCharackter(letterTexture,letterCounter);
		players[i].getUpdateCharackters().clear();
	}

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();

		clock.restart();
		time = time / 800;

		Vector2i pixelPos = Mouse::getPosition(window);//забираем коорд курсора
		Vector2f pos = window.mapPixelToCoords(pixelPos);//переводим их в игровые (уходим от коорд окна)
		//std::cout << pixelPos.x << "\n";//смотрим на координату Х позиции курсора в консоли (она не будет больше ширины окна)
		//std::cout << pos.y << "\n";//смотрим на Х,которая преобразовалась в мировые координаты

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			if (event.type == Event::MouseButtonPressed) //если нажата клавиша мыши
			{
				if (event.key.code == Mouse::Left) //а именно левая
				{
					if (text.getGlobalBounds().contains(pos.x, pos.y))
					{
						////
						firstMove = false;
						score = 0;
						for (int i = 0; i < temp.size(); i++)
						{
							score += temp[i].getScore();
						}
						if (wordX2)
						{
							score *= 2;
							wordX2 = false;
						}
						if (wordX3)
						{
							score *= 3;
							wordX3 = false;
						}
						players[player].setScore(score);
						temp.clear();


						////
						if (player == countOfPlayers - 1)
						{
							player = 0;
						}
						else
						{
							player++;
						}

						PlayerText.setString("Player " + str(player + 1) + " \nis playing!");
						PlayerScore.setString("Score: " + str(players[player].getPlayerScore()));
						/*cout << "Player " << player + 1 << "\n" << players[player].getPlayerScore() << endl;
						for (int i = 0; i < players[player].getUpdateCharackters().size(); i++)
						{
							cout << players[player].getUpdateCharackters()[i] << endl;
						}*/
						//////////
						players[player].setPlayerCharackter(letterTexture,letterCounter);
						players[player].getUpdateCharackters().clear();
						//////////
						countOfSprites = 0;
						//temp.clear();
					}

					if (pos.y > 825 && pos.y < 875 && pos.x > 60 && pos.x < 530)
					{
						i = (pos.x / 60) - 1;
						//cout << i << endl;
						if (players[player].getLetter()[i].getGlobalBounds().contains(pos.x, pos.y))//и при этом координата курсора попадает в спрайт
						{
							dX = pos.x - players[player].getLetter()[i].getPosition().x;//делаем разность между позицией курсора и спрайта.для корректировки нажатия
							dY = pos.y - players[player].getLetter()[i].getPosition().y;//тоже самое по игреку
							isMove = true;//можем двигать спрайт							
						}
					}
					if (backButton.getGlobalBounds().contains(pos.x, pos.y) && backButton.getColor() != Color::Red) //удаление инфы про букву
					{
						players[player].getLetter()[i].setColor(Color::White);
						players[player].getLetter()[i].setPosition(60 * (i + 1), 825);
						players[player].getLetter()[i].setActive(true);
						drawableLetters.erase(drawableLetters.end() - 1);
						Field[setY][setX] = '.';
						//players[player].setScore(-players[player].getLetter()[i].getScore());
						players[player].getUpdateCharackters().erase(players[player].getUpdateCharackters().end() - 1);
						countOfSprites--;

						temp.erase(temp.end() - 1);
					}
				}
			}

			if (event.type == Event::MouseButtonReleased) //если отпустили клавишу
			{
				if (event.key.code == Mouse::Left && i != -1) //а именно левую(проверка на -1 для избавление от дефолтного взаимодействия с 0 тайлом)
				{
					isMove = false;//то не можем двигать спрайт
					///
					if (players[player].getLetter()[i].getActive())
					{
						setX = pos.x / 53;
						setY = pos.y / 53;
						if (check(Field, setX, setY, firstMove)) //добавление инфы про букву 
						{
							players[player].getLetter()[i].setPosition(setX * 53 + 4, setY * 53 + 4);
							players[player].getLetter()[i].setActive(false);//букву невозможно двигать
							players[player].getLetter()[i].setColor(Color::White);//даем ему прежний цвет
							drawableLetters.insert(drawableLetters.end(), players[player].getLetter()[i]); //добавления буквы в вектор для постоянного отображения на игровом поле
							Field[setY][setX] = players[player].getLetter()[i].getCharacter();
							//players[player].setScore(players[player].getLetter()[i].getScore());
							players[player].setUpdateCharackter(i);
							countOfSprites++;

							temp.insert(temp.end(), players[player].getLetter()[i]);
							if (check2LMultiplie(setX, setY))
							{
								temp[temp.size() - 1].setScore(temp[temp.size() - 1].getScore() * 2);
							}
							if (check3LMultiplie(setX, setY))
							{
								temp[temp.size() - 1].setScore(temp[temp.size() - 1].getScore() * 3);
							}
							if (check2WMultiplie(setX, setY))
							{
								wordX2 = true;
							}
							if (check3WMultiplie(setX, setY))
							{
								wordX3 = true;
							}
							//cout << temp[temp.size() - 1].getScore() << endl;
							/*cout << check2LMultiplie(setX, setY) << endl;
							cout << check3LMultiplie(setX, setY) << endl;
							cout << check2WMultiplie(setX, setY) << endl << endl;*/
						}
						else
						{
							players[player].getLetter()[i].setColor(Color::White);
							players[player].getLetter()[i].setPosition(60 * (i + 1), 825);
						}

					}
				}
				if (event.key.code == Mouse::Right)
				{
					output(Field);
					for (int i = 0; i < temp.size(); i++)
					{
						cout << temp[i] << endl;
					}
				}
			}
			if (isMove) //если можем двигать
			{
				Vector2i coursorPos;
				players[player].getLetter()[i].setColor(Color::Yellow);//красим спрайт в зеленый 
				players[player].getLetter()[i].setPosition(pos.x - dX, pos.y - dY);//можно и так написать,если у вас нету х и у в классе игрока
				if (pos.x > 800)
				{
					coursorPos.x = 801;
					coursorPos.y = pos.y;
					Mouse::setPosition(coursorPos, window);
				}
				if (pos.x < 0)
				{
					coursorPos.x = 0;
					coursorPos.y = pos.y;
					Mouse::setPosition(coursorPos, window);
				}
				if (pos.y > 900)
				{
					coursorPos.x = pos.x;
					coursorPos.y = 900;
					Mouse::setPosition(coursorPos, window);
				}
				if (pos.y < 0)
				{
					coursorPos.x = pos.x;
					coursorPos.y = 0;
					Mouse::setPosition(coursorPos, window);
				}

			}
		}

		if (text.getGlobalBounds().contains(pos.x, pos.y))
		{
			text.setFillColor(Color::Yellow);
		}
		else
		{
			text.setFillColor(Color::White);
		}

		if (backButton.getGlobalBounds().contains(pos.x, pos.y) && countOfSprites == 0)
		{
			backButton.setColor(Color::Red);
		}
		else
		{
			backButton.setColor(Color::White);
		}
		window.clear();
		window.draw(background);
		window.draw(gameField);
		for (int i = 0; i < 8; i++)
		{
			window.draw(players[player].getLetter()[i]);
		}
		window.draw(text);
		window.draw(PlayerText);
		window.draw(PlayerScore);
		window.draw(backButton);
		for (int i = 0; i < drawableLetters.size(); i++)
		{
			window.draw(drawableLetters[i]);
		}
		window.display();
	}
	delete[] players;
	return EXIT_SUCCESS;
}