// Snake_Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
#include<Windows.h>
using namespace std;
bool Gameover;
int width = 20, height = 20;
int tailX[400], tailY[400];
int ntail = 0;
int x, y, fruitX, fruitY, score;
enum edirections { STOP = 0, LEFT, RIGHT, UP, DOWN };
edirections dir;

void Setup() {
	Gameover = false;
	dir = STOP;
	x = width / 2;
	y = width / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}

void Draw() {
	system("cls");
	cout << "Score : " << score << endl;
	for (int i = 0;i <= width;i++) cout << "#";
	cout << endl;
	for (int i = 0;i < height;i++) {
		for (int j = 0;j <= width;j++) {
			if (j == 0) cout << "#";
			else if (j == width) cout << "#";
			else if (j == x && i == y) cout << "O";
			else if (j == fruitX && i == fruitY) cout << "F";
			else {
				bool check = false;
				for (int k = 0;k < ntail;k++) {
					if (tailX[k] == j && tailY[k] == i) {
						cout << "o";
						check = true;
					}
				}
				if(!check)
				cout << " ";
			}
		}
		cout << endl;
	}

	for (int i = 0;i <= width;i++) cout << "#";
	cout << endl;
}


void input() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'd':
			dir = RIGHT;
			break;
		case 'a':
			dir = LEFT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			Gameover = true;
			break;
		}
	}
}

void Logic() {
	int prevX = tailX[0];
	int prevY = tailY[0];
	tailX[0] = x;
	tailY[0] = y;
	int prevX1, prevY1;
	for (int i = 1;i < ntail;i++) {
		prevX1 = tailX[i];
		prevY1 = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prevX1;
		prevY = prevY1;
	}
	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
	if (min(x, y) == -1 || x == width || y == height) {
		Gameover = true;
	}
	for (int i = 0;i < ntail;i++) {
		if (tailX[i] == x && tailY[i] == y) Gameover = true;
	}
	if (x == fruitX && y == fruitY) {
		score+=10;
		fruitX = rand() % width;
		fruitY = rand() % height;
		ntail++;
	}
}


int main()
{
	Setup();
	while (!Gameover) {
		Draw();
		input();
		Logic();
		Sleep(150);
	}
}