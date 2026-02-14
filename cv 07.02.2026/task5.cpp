#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	char Symbols[201];
	for (int i{0}; i<201; i++)
		Symbols[i] = ' ';

	unsigned int Values[200];
	for (int i{0}; i<200; i++)
		Values[i] = 0;

	ifstream file("lorem.txt");

	int k=0;
	for (char c; file.get(c);)
	{
		bool isExists = false;

		for (int i{0}; i < k; i++)
		{
			if (Symbols[i] == c)
			{
				isExists = true;
				Values[i]++;
				break;
			}
		}

		if (!isExists)
		{
			Symbols[k] = c;
			Values[k]++;
			k++;
		}
	}

	file.close();

	for (int i{0}; i<k; i++)
	{
		if (Symbols[i]==10)
		{
			cout << "LF" << " " << Values[i] << endl;
		}
		else
			cout << Symbols[i] << " " << Values[i] << endl;
	}

	return 0;
}