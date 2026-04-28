#include <iostream>
#include "Field.h"
#include <cstdlib>
using namespace std;

int main(void)
{
	Field field(true);
	while (!field.isOver())
	{
		field.print();
		cout << "It's " <<
			(field.isRedTurnNow() ? "red" : "yellow") <<
			" turn, enter column (1-" << FIELD_WIDTH << ")" << endl;
		int column; cin >> column;
		field.makeTurn(column);
		system("cls");
	}

	system("cls");
	field.print();
	field.printResult();

	return 0;
}

