#include "Field.h"
#include <iostream>
using namespace std;

char cells_name[][17] = { ' ', 'R', 'Y' };
const int DIR_NUMBER = 4;
const int di[] = { 1, 0, 1, 1 };
const int dj[] = { 0, 1, -1, 1 };
const int WIN_LENGTH = 4;

Field::Field(bool isRedFirst)
{
	clear(isRedFirst);
}
void Field::clear(bool isRedFirst)
{
	isRedTurn = isRedFirst;
	winner = EMPTY;
	for (int i = 0; i < FIELD_WIDTH; i++)
		for (int j = 0; j < FIELD_HEIGHT; j++)
			cells[i][j] = EMPTY;
}
bool Field::makeTurn(int column)
{
	if (winner != EMPTY || column < 1 || column > FIELD_WIDTH)
		return false;
	int i = column - 1;
	for (int j = 0; j < FIELD_HEIGHT; j++)
		if (cells[i][j] == EMPTY)
		{
			cells[i][j] = isRedTurn ? RED : YELLOW;
			checkWinner();
			isRedTurn = !isRedTurn;
			return true;
		}
	return false;
}
void Field::checkWinner()
{
	for (int i = 0; i < FIELD_WIDTH; i++)
		for (int j = 0; j < FIELD_HEIGHT; j++)
		{
			Cell start = cells[i][j];
			if (start == EMPTY) continue;
			for (int dir = 0; dir < DIR_NUMBER; dir++)
			{
				int length = 0, iline = i, jline = j;
				while (++length < WIN_LENGTH)
				{
					iline += di[dir];
					jline += dj[dir];
					if (iline < 0 || iline >= FIELD_WIDTH ||
						jline < 0 || jline >= FIELD_HEIGHT)
						break;
					if (cells[iline][jline] != start) break;
				}
				if (length == WIN_LENGTH)
				{
					winner = start;
					return;
				}
			}
		}
}
bool Field::isOver() const
{
	if (winner != EMPTY) { return true; }
	for (int i = 0; i < FIELD_WIDTH; i++) {
		for (int j = 0; j < FIELD_HEIGHT; j++) {
			if (cells[i][j] == EMPTY) { return false; }
		}
	}
	return true;
}

bool Field::isRedTurnNow() const
{
	return isRedTurn;
}

int countDigits(int n)
{
	int c = 0;
	n = abs(n);
	do
	{
		n /= 10;
		c++;
	} while (n > 0);
	return c;
}

void Field::print() const
{
	for (int i = 0; i < FIELD_WIDTH; i++)
		cout << " " << i + 1;
	cout << endl;

	for (int i = 0; i < FIELD_WIDTH; i++)
	{
		cout << "-";
		for (int j = 0; j < countDigits(i); j++)
			cout << "-";
	}
	cout << "-" << endl;

	for (int j = FIELD_HEIGHT-1; j >= 0; j--)
	{
		for (int i = 0; i < FIELD_WIDTH; i++)
		{
			if (cells[i][j] == RED)
			{
				for (int x = 0; x < countDigits(i);x++)
					cout << " ";
				cout << "R";
			}

			else if (cells[i][j] == YELLOW)
			{
				for (int x = 0; x < countDigits(i);x++)
					cout << " ";
				cout << "Y";
			}
			else
			{
				cout << " ";
				for (int x=0; x<countDigits(i);x++)
					cout << " ";
			}
		}
		cout << endl;
	}

	for (int i = 0; i < FIELD_WIDTH; i++)
	{
		cout << "-";
		for (int j = 0; j < countDigits(i); j++)
			cout << "-";
	}
	cout << "-" << endl;
}

void Field::printResult() const
{
	if (winner == RED)
		cout << "Red wins";
	else if (winner == YELLOW)
		cout << "Yellow wins";
	else
		cout << "Tie";
}
