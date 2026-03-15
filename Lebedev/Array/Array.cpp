#include <iostream>
#include "Array.h"
using namespace std;

int main() {
	Array<int> arr(4);
	for (int i = 0; i < 4; i++)
		arr.insert(i*i);
	cout << arr << endl;

	Array<int> arr1(6);
	for (int i = 0; i < 4; i++)
		arr1.insert(i + 1);
	cout << arr1 << endl;

	cout << arr1.getSize() << endl<<endl;


	for (int i = 0; i < 8; i += 2)
		arr1.insert(10 + i, i);
	cout << arr1 << endl;

	for (int i = 1; i < 8; i += 2)
		arr1[i] = 20 + i;
	cout << arr1 << endl;

	for (int i = 6; i >= 0; i -= 3)
		arr1.remove(i);
	cout << arr1 << endl;

	return 0;
}