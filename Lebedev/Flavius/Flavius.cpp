#include <iostream>
#include <chrono>
#include "Array.h"

int main()
{
    int N;
    cout << "Enter N: ";
    cin >> N;

    int k;
    cout << "Enter k: ";
    cin >> k;

    auto start = chrono::high_resolution_clock::now();
    Array<int> arr(N);
    for (int i = 0; i < N;i++)
        arr.insert(i+1);

    int c=0;

    while (arr.getSize() != 1)
    {
        c = (c + k - 1) % arr.getSize();
        arr.remove(c);
    }

    auto end = chrono::high_resolution_clock::now();

    cout << endl << "Last: " << arr[0] << endl;
    chrono::duration<double> diff = end - start;
    cout << "Execution time: " << diff.count() << " seconds" << endl;
    return 0;
}
